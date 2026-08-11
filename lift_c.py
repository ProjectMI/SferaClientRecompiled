from __future__ import annotations

import hashlib
import json
import re
import shutil
import struct
import subprocess
import time
from collections import Counter, deque
from dataclasses import dataclass
from pathlib import Path

from pe32 import PE32, PEFormatError
from pe_analysis import code_free_payload, recover_callback_targets, recover_jump_tables, recover_lookup_data, uncovered_executable_data
from x86_decode import DecodedInstruction, DecodedOperand, DecodedProgram, decode_program, decode_reachable


_PROCESS_MODULE_ARGUMENTS = {("dinput8.dll", "DirectInput8Create"): 0}
_X87_ARITHMETIC = {"fadd", "faddp", "fsub", "fsubp", "fsubr", "fsubrp", "fmul", "fmulp", "fdiv", "fdivp", "fdivr", "fdivrp", "fiadd", "fisub", "fisubr", "fimul", "fidiv", "fidivr"}
_CONDITIONS = {
    "o": "((cpu->eflags & LIFT_FLAG_OF) != 0u)",
    "no": "((cpu->eflags & LIFT_FLAG_OF) == 0u)",
    "b": "((cpu->eflags & LIFT_FLAG_CF) != 0u)",
    "ae": "((cpu->eflags & LIFT_FLAG_CF) == 0u)",
    "e": "((cpu->eflags & LIFT_FLAG_ZF) != 0u)",
    "ne": "((cpu->eflags & LIFT_FLAG_ZF) == 0u)",
    "be": "((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u)",
    "a": "((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u)",
    "s": "((cpu->eflags & LIFT_FLAG_SF) != 0u)",
    "ns": "((cpu->eflags & LIFT_FLAG_SF) == 0u)",
    "p": "((cpu->eflags & LIFT_FLAG_PF) != 0u)",
    "np": "((cpu->eflags & LIFT_FLAG_PF) == 0u)",
    "l": "(((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u)",
    "ge": "((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)",
    "le": "(((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u))",
    "g": "(((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u))",
}


def c_string(value: str) -> str:
    pieces = ['"']
    for byte in value.encode("utf-8"):
        if byte == 0x22:
            pieces.append('\\"')
        elif byte == 0x5C:
            pieces.append("\\\\")
        elif 0x20 <= byte <= 0x7E:
            pieces.append(chr(byte))
        else:
            pieces.append(f"\\x{byte:02X}")
    pieces.append('"')
    return "".join(pieces)


def symbol(value: str) -> str:
    cleaned = re.sub(r"[^A-Za-z0-9_]", "_", value)
    if not cleaned or cleaned[0].isdigit():
        cleaned = "generated_" + cleaned
    return cleaned


def u32(value: int) -> str:
    return f"UINT32_C(0x{value & 0xFFFFFFFF:08X})"


def function_name(pe: PE32, rva: int) -> str:
    return f"sfera_sub_{pe.image_base + rva:08X}"


def import_name(index: int, dll: str, name: str | None, ordinal: int | None) -> str:
    label = name if name else f"ordinal_{ordinal or 0}"
    return symbol(f"sfera_import_{index:03d}_{dll}_{label}")


@dataclass(frozen=True)
class RecoveredFunction:
    seed: int
    instructions: tuple[DecodedInstruction, ...]
    leaders: frozenset[int]


@dataclass(frozen=True)
class Recovery:
    instructions: tuple[DecodedInstruction, ...]
    functions: tuple[RecoveredFunction, ...]
    callbacks: tuple[int, ...]
    jump_entries: tuple[tuple[int, int], ...]
    lookup_data: tuple[tuple[int, bytes], ...]
    switch_targets: dict[int, tuple[int, ...]]


@dataclass(frozen=True)
class SemanticSummaries:
    config_lookup_target: int = 0
    config_text_pointer_address: int = 0
    config_text_length_address: int = 0
    config_text_capacity: int = 0
    unsigned_decimal_target: int = 0
    unsigned_decimal_callsite: int = 0


def _is_register(operand: DecodedOperand, name: str) -> bool:
    return operand.kind == "register" and operand.reg == name


def _is_immediate(operand: DecodedOperand, value: int) -> bool:
    return operand.kind == "immediate" and operand.imm == value


def _is_memory(operand: DecodedOperand, base: str | None = None, displacement: int | None = None) -> bool:
    return operand.kind == "memory" and operand.base == base and operand.index is None and (displacement is None or operand.displacement == displacement)


def _literal_vas(pe: PE32, literal: bytes) -> set[int]:
    matches: set[int] = set()
    for section in pe.sections:
        raw = pe.data[section.raw_offset:section.raw_offset + section.raw_size]
        offset = raw.find(literal)
        while offset >= 0:
            matches.add(pe.image_base + section.virtual_address + offset)
            offset = raw.find(literal, offset + 1)
    return matches


def _config_storage_contract(instructions: tuple[DecodedInstruction, ...], index: int, pointer_address: int) -> tuple[int, int]:
    begin = max(0, index - 64)
    for candidate_index in range(index - 1, begin - 1, -1):
        candidate = instructions[candidate_index]
        if candidate.mnemonic != "cmp" or len(candidate.operands) != 2 or candidate.operands[0].kind != "register" or candidate.operands[1].kind != "immediate":
            continue
        capacity = candidate.operands[1].imm or 0
        register = candidate.operands[0].reg
        if capacity < 4096 or capacity >= 0xFFFFFFFF:
            continue
        following = instructions[candidate_index + 1:index]
        clamps = any(item.mnemonic == "mov" and len(item.operands) == 2 and _is_register(item.operands[0], register or "") and _is_immediate(item.operands[1], capacity) for item in following)
        assigns_pointer = any(item.mnemonic == "mov" and len(item.operands) == 2 and _is_memory(item.operands[0], displacement=pointer_address) and item.operands[1].kind == "immediate" for item in following)
        length_addresses = {item.operands[0].displacement for item in following if item.mnemonic == "mov" and len(item.operands) == 2 and _is_memory(item.operands[0]) and _is_register(item.operands[1], register or "")}
        if clamps and assigns_pointer and len(length_addresses) == 1:
            return capacity, next(iter(length_addresses))
    return 0, 0


def _discover_config_summary(pe: PE32, instructions: tuple[DecodedInstruction, ...]) -> tuple[int, int, int, int]:
    candidates: set[tuple[int, int, int, int]] = set()
    for index in range(len(instructions) - 48):
        first, second, third, fourth, fifth = instructions[index:index + 5]
        if first.mnemonic != "mov" or len(first.operands) != 2 or not _is_register(first.operands[0], "edx") or not _is_memory(first.operands[1]):
            continue
        if second.mnemonic != "mov" or len(second.operands) != 2 or not _is_register(second.operands[0], "al") or not _is_memory(second.operands[1], "edx", 0):
            continue
        if third.mnemonic != "push" or len(third.operands) != 1 or not _is_register(third.operands[0], "esi") or fourth.mnemonic != "push" or len(fourth.operands) != 1 or not _is_register(fourth.operands[0], "edi"):
            continue
        if fifth.mnemonic != "mov" or len(fifth.operands) != 2 or not _is_register(fifth.operands[0], "edi") or not _is_memory(fifth.operands[1], "esp", 12):
            continue
        window = instructions[index:index + 48]
        delimiters = {item.operands[1].imm for item in window if item.mnemonic == "cmp" and len(item.operands) == 2 and _is_register(item.operands[0], "al") and item.operands[1].kind == "immediate"}
        returns_with_four = any(item.mnemonic == "ret" and len(item.operands) == 1 and _is_immediate(item.operands[0], 4) for item in window)
        pointer_address = first.operands[1].displacement
        capacity, length_address = _config_storage_contract(instructions, index, pointer_address)
        if {9, 13, 32}.issubset(delimiters) and returns_with_four and capacity and length_address:
            candidates.add((pe.image_base + first.rva, pointer_address, length_address, capacity))
    if len(candidates) > 1:
        raise PEFormatError("Config lookup normalization is ambiguous; refusing to bind it to a guessed address")
    return next(iter(candidates), (0, 0, 0, 0))


def _discover_unsigned_decimal_summary(pe: PE32, instructions: tuple[DecodedInstruction, ...]) -> tuple[int, int]:
    literal_vas = _literal_vas(pe, b"NEW_FONT_\0")
    if not literal_vas:
        return 0, 0
    instruction_rvas = {item.rva for item in instructions}
    candidates: set[tuple[int, int]] = set()
    for index in range(5, len(instructions) - 16):
        literal_push = instructions[index]
        if literal_push.mnemonic != "push" or len(literal_push.operands) != 1 or literal_push.operands[0].kind != "immediate" or literal_push.operands[0].imm not in literal_vas:
            continue
        length_push, result_move, call, destination, source = instructions[index - 1], instructions[index - 2], instructions[index - 3], instructions[index - 4], instructions[index - 5]
        if length_push.mnemonic != "push" or len(length_push.operands) != 1 or not _is_immediate(length_push.operands[0], len("NEW_FONT_")):
            continue
        if result_move.mnemonic != "mov" or len(result_move.operands) != 2 or result_move.operands[0].kind != "register" or not _is_register(result_move.operands[1], "eax"):
            continue
        if call.mnemonic != "call" or call.branch_target_rva is None or call.branch_target_rva not in instruction_rvas:
            continue
        if destination.mnemonic != "lea" or len(destination.operands) != 2 or not _is_register(destination.operands[0], "ecx") or not _is_memory(destination.operands[1], "esp"):
            continue
        if source.mnemonic != "lea" or len(source.operands) != 2 or not _is_register(source.operands[0], "edx") or not _is_memory(source.operands[1], "esp"):
            continue
        result_register = result_move.operands[0].reg
        result_is_used = any(item.mnemonic == "push" and len(item.operands) == 1 and _is_register(item.operands[0], result_register or "") for item in instructions[index + 1:index + 17])
        if result_is_used:
            candidates.add((pe.image_base + call.branch_target_rva, pe.image_base + call.rva))
    if len(candidates) != 1:
        raise PEFormatError("NEW_FONT_ decimal normalization was not identified unambiguously; refusing to generate code that can corrupt font keys")
    return next(iter(candidates))


def discover_semantic_summaries(pe: PE32, instructions: tuple[DecodedInstruction, ...]) -> SemanticSummaries:
    config_target, config_pointer, config_length, config_capacity = _discover_config_summary(pe, instructions)
    decimal_target, decimal_callsite = _discover_unsigned_decimal_summary(pe, instructions)
    if decimal_target and not all((config_target, config_pointer, config_length, config_capacity)):
        raise PEFormatError("NEW_FONT_ requires a normalized config lookup, but its storage contract was not recovered")
    return SemanticSummaries(config_target, config_pointer, config_length, config_capacity, decimal_target, decimal_callsite)


def _switch_targets(pe: PE32, instructions: tuple[DecodedInstruction, ...], jump_entries: list[tuple[int, int]]) -> dict[int, tuple[int, ...]]:
    entries = {rva: target - pe.image_base for rva, target in jump_entries}
    result: dict[int, tuple[int, ...]] = {}
    for instruction in instructions:
        if instruction.mnemonic != "jmp" or not instruction.operands:
            continue
        operand = instruction.operands[0]
        if operand.kind != "memory" or operand.base is not None or operand.index is None or operand.scale != 4 or operand.width != 32:
            continue
        cursor = (operand.displacement & 0xFFFFFFFF) - pe.image_base
        targets: list[int] = []
        while cursor in entries:
            targets.append(entries[cursor])
            cursor += 4
        if targets:
            result[instruction.rva] = tuple(dict.fromkeys(targets))
    return result


def _function_successors(instruction: DecodedInstruction, switches: dict[int, tuple[int, ...]]) -> tuple[int, ...]:
    if instruction.flow == "next":
        return (instruction.next_rva,)
    if instruction.flow in {"call", "indirect_call"}:
        return (instruction.next_rva,)
    if instruction.flow == "conditional_branch":
        return (instruction.next_rva,) + ((instruction.branch_target_rva,) if instruction.branch_target_rva is not None else ())
    if instruction.flow == "unconditional_branch":
        if instruction.branch_target_rva is not None:
            return (instruction.branch_target_rva,)
        return switches.get(instruction.rva, ())
    if instruction.flow == "indirect_branch":
        return switches.get(instruction.rva, ())
    return ()


def recover_functions(pe: PE32, program: DecodedProgram) -> Recovery:
    jump_entries = recover_jump_tables(pe, program)
    lookup_data = recover_lookup_data(pe, program.instructions)
    callbacks = recover_callback_targets(pe, jump_entries, lookup_data)
    decode_seeds = {pe.entry_rva, *callbacks, *(target - pe.image_base for _, target in jump_entries)}
    instructions = decode_reachable(pe, decode_seeds)
    by_rva = {instruction.rva: instruction for instruction in instructions}
    function_seeds = {pe.entry_rva, *callbacks}
    function_seeds.update(instruction.branch_target_rva for instruction in instructions if instruction.flow == "call" and instruction.branch_target_rva in by_rva)
    switches = _switch_targets(pe, instructions, jump_entries)
    functions: list[RecoveredFunction] = []
    covered: set[int] = set()
    for seed in sorted(function_seeds):
        queue = deque([seed])
        body: set[int] = set()
        while queue:
            rva = queue.popleft()
            if rva in body or rva not in by_rva or (rva in function_seeds and rva != seed):
                continue
            body.add(rva)
            queue.extend(_function_successors(by_rva[rva], switches))
        if not body:
            raise PEFormatError(f"Recovered function 0x{pe.image_base + seed:08X} has no decoded body")
        leaders = {seed}
        for rva in body:
            instruction = by_rva[rva]
            successors = _function_successors(instruction, switches)
            if instruction.flow in {"call", "indirect_call", "conditional_branch"} and instruction.next_rva in body:
                leaders.add(instruction.next_rva)
            leaders.update(target for target in successors if target in body and target != instruction.next_rva)
        ordered = tuple(by_rva[rva] for rva in sorted(body))
        functions.append(RecoveredFunction(seed, ordered, frozenset(leaders)))
        covered.update(body)
    if covered != set(by_rva):
        missing = min(set(by_rva) - covered)
        raise PEFormatError(f"Function recovery left reachable code unowned at 0x{pe.image_base + missing:08X}")
    return Recovery(instructions, tuple(functions), tuple(callbacks), tuple(jump_entries), tuple(lookup_data), switches)


def _process_module_argument(dll: str, name: str | None) -> int:
    return _PROCESS_MODULE_ARGUMENTS.get((dll.lower(), name or ""), -1)


def emit_source_header(pe: PE32, recovery: Recovery, output: Path) -> tuple[bytes, list[tuple[int, int, int]], int]:
    callback_bytes = {byte for rva in recovery.callbacks for byte in range(rva, rva + 5)}
    jump_bytes = {byte for rva, _ in recovery.jump_entries for byte in range(rva, rva + 4)}
    lookup_bytes = {byte for rva, data in recovery.lookup_data for byte in range(rva, rva + len(data))}
    if callback_bytes & jump_bytes or callback_bytes & lookup_bytes or jump_bytes & lookup_bytes:
        raise PEFormatError("Recovered callback stubs, switch tables, and lookup data overlap")
    missing_data = uncovered_executable_data(pe, recovery.instructions, list(recovery.jump_entries), list(recovery.lookup_data))
    executable_ranges = [(section.virtual_address, section.virtual_address + section.mapped_size) for section in pe.sections if section.executable]
    restored_bytes = jump_bytes | lookup_bytes
    relocation_rvas: list[int] = []
    mapped = pe.mapped_image()
    for relocation in pe.relocations:
        if relocation.kind != 3 or relocation.rva + 4 > pe.size_of_image:
            continue
        in_executable = any(begin <= relocation.rva < end for begin, end in executable_ranges)
        if not in_executable or all(relocation.rva + offset in restored_bytes for offset in range(4)):
            source_va = struct.unpack_from("<I", mapped, relocation.rva)[0]
            if not pe.image_base <= source_va < pe.image_base + pe.size_of_image:
                raise PEFormatError(f"Relocation 0x{relocation.rva:08X} does not contain an image address")
            relocation_rvas.append(relocation.rva)
    payload = code_free_payload(pe)
    hex_chunks = [payload[start:start + 4096].hex().upper() for start in range(0, len(payload), 4096)]
    sections = [f"    {{{c_string(item.name)}, 0x{item.virtual_address:08X}u, 0x{item.virtual_size:08X}u, 0x{item.raw_offset:08X}u, 0x{item.raw_size:08X}u, {(1 if item.readable else 0) | (2 if item.writable else 0) | (4 if item.executable else 0)}u}}," for item in pe.sections]
    imports = [f"    {{{c_string(item.dll)}, {c_string(item.name or '')}, 0x{item.iat_rva:08X}u, {item.ordinal or 0}u, {'true' if item.ordinal is not None else 'false'}, {_process_module_argument(item.dll, item.name)}}}," for item in pe.imports]
    callbacks = [f"    {{0x{rva:08X}u}}," for rva in recovery.callbacks]
    jumps = [f"    {{0x{rva:08X}u, 0x{target:08X}u}}," for rva, target in recovery.jump_entries]
    recovered = [f"    {{0x{rva:08X}u, {c_string(data.hex().upper())}}}," for rva, data in recovery.lookup_data]
    relocations = [f"    {{0x{rva:08X}u}}," for rva in relocation_rvas]
    chunk_defs = [f"inline constexpr char kMappedPayloadHex_{index}[] = {c_string(chunk)};" for index, chunk in enumerate(hex_chunks)]
    chunk_rows = [f"    {{kMappedPayloadHex_{index}, sizeof(kMappedPayloadHex_{index}) - 1u}}," for index in range(len(hex_chunks))]
    content = f'''#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <array>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <string_view>
#include <vector>

namespace lifted {{

inline constexpr std::uint8_t kRead = 1u;
inline constexpr std::uint8_t kWrite = 2u;
inline constexpr std::uint8_t kExecute = 4u;
inline constexpr std::uint32_t kSourceImageBase = 0x{pe.image_base:08X}u;
inline constexpr std::uint32_t kEntryRva = 0x{pe.entry_rva:08X}u;
inline constexpr std::uint32_t kImageSize = 0x{pe.size_of_image:08X}u;
inline constexpr std::uint32_t kHeadersSize = 0x{pe.size_of_headers:08X}u;
inline constexpr std::uint32_t kStackReserve = 0x{pe.stack_reserve:08X}u;
inline constexpr std::uint16_t kMachine = 0x{pe.machine:04X}u;
inline constexpr std::size_t kMappedPayloadSize = {len(payload)}u;
inline constexpr std::string_view kClientExecutableName = {c_string(pe.path.name)};

struct SectionDescriptor {{ std::string_view name; std::uint32_t virtual_address; std::uint32_t virtual_size; std::uint32_t raw_offset; std::uint32_t raw_size; std::uint8_t access; }};
struct ImportDescriptor {{ std::string_view dll; std::string_view name; std::uint32_t iat_rva; std::uint16_t ordinal; bool by_ordinal; std::int8_t process_module_argument; }};
struct CallbackDescriptor {{ std::uint32_t rva; }};
struct JumpTableDescriptor {{ std::uint32_t rva; std::uint32_t target; }};
struct RecoveredDataDescriptor {{ std::uint32_t rva; std::string_view hex; }};
struct RelocationDescriptor {{ std::uint32_t rva; }};
struct HexChunk {{ const char* data; std::size_t size; }};

inline constexpr std::array<SectionDescriptor, {len(sections)}> kSections = {{{{
{chr(10).join(sections)}
}}}};
inline constexpr std::array<ImportDescriptor, {len(imports)}> kImports = {{{{
{chr(10).join(imports)}
}}}};
inline constexpr std::array<CallbackDescriptor, {len(callbacks)}> kCallbacks = {{{{
{chr(10).join(callbacks)}
}}}};
inline constexpr std::array<JumpTableDescriptor, {len(jumps)}> kJumpTableEntries = {{{{
{chr(10).join(jumps)}
}}}};
inline constexpr std::array<RecoveredDataDescriptor, {len(recovered)}> kRecoveredData = {{{{
{chr(10).join(recovered)}
}}}};
inline constexpr std::array<RelocationDescriptor, {len(relocations)}> kLocalRelocations = {{{{
{chr(10).join(relocations)}
}}}};

{chr(10).join(chunk_defs)}
inline constexpr std::array<HexChunk, {len(chunk_rows)}> kMappedPayloadHex = {{{{
{chr(10).join(chunk_rows)}
}}}};

inline std::uint8_t decode_hex_digit(char value) {{
    if (value >= '0' && value <= '9') {{ return static_cast<std::uint8_t>(value - '0'); }}
    if (value >= 'A' && value <= 'F') {{ return static_cast<std::uint8_t>(value - 'A' + 10); }}
    throw std::runtime_error("Corrupt generated hexadecimal payload");
}}

inline std::vector<std::uint8_t> decode_mapped_payload() {{
    std::vector<std::uint8_t> result;
    result.reserve(kMappedPayloadSize);
    for (const HexChunk chunk : kMappedPayloadHex) {{
        if ((chunk.size & 1u) != 0u) {{ throw std::runtime_error("Odd hexadecimal chunk length"); }}
        for (std::size_t index = 0; index < chunk.size; index += 2u) {{ result.push_back(static_cast<std::uint8_t>((decode_hex_digit(chunk.data[index]) << 4u) | decode_hex_digit(chunk.data[index + 1u]))); }}
    }}
    if (result.size() != kMappedPayloadSize) {{ throw std::runtime_error("Embedded payload size mismatch"); }}
    return result;
}}

}} // namespace lifted
'''
    output.write_text(content, encoding="utf-8", newline="\n")
    return payload, missing_data, len(relocation_rvas)


class CLowerer:
    def __init__(self, pe: PE32, recovery: Recovery, summaries: SemanticSummaries):
        self.pe = pe
        self.recovery = recovery
        self.summaries = summaries
        self.function_seeds = {function.seed for function in recovery.functions}
        self.function_bodies = {function.seed: frozenset(item.rva for item in function.instructions) for function in recovery.functions}
        self.import_by_va = {pe.image_base + item.iat_rva: index for index, item in enumerate(pe.imports)}
        self.import_symbols = [import_name(index, item.dll, item.name, item.ordinal) for index, item in enumerate(pe.imports)]
        self.config_lookup_rva = summaries.config_lookup_target - pe.image_base if summaries.config_lookup_target else None
        self.unsigned_decimal_rva = summaries.unsigned_decimal_target - pe.image_base if summaries.unsigned_decimal_target else None
        self.unsigned_decimal_callsite_rva = summaries.unsigned_decimal_callsite - pe.image_base if summaries.unsigned_decimal_callsite else None
        if self.config_lookup_rva is not None and self.config_lookup_rva not in self.function_seeds:
            raise PEFormatError("Normalized config lookup is not a recovered function entry")
        if self.unsigned_decimal_rva is not None:
            matches = [item for item in recovery.instructions if item.rva == self.unsigned_decimal_callsite_rva and item.mnemonic == "call" and item.branch_target_rva == self.unsigned_decimal_rva]
            if len(matches) != 1:
                raise PEFormatError("Normalized NEW_FONT_ decimal callsite does not match one recovered direct call")

    def source_va(self, rva: int) -> int:
        return self.pe.image_base + rva

    def local_va(self, rva: int) -> str:
        return f"lift_image_va({u32(self.source_va(rva))})"

    @staticmethod
    def _register_storage(name: str) -> tuple[str, int, int]:
        mapping = {
            "al": ("eax", 0, 8), "ah": ("eax", 8, 8), "ax": ("eax", 0, 16), "eax": ("eax", 0, 32),
            "cl": ("ecx", 0, 8), "ch": ("ecx", 8, 8), "cx": ("ecx", 0, 16), "ecx": ("ecx", 0, 32),
            "dl": ("edx", 0, 8), "dh": ("edx", 8, 8), "dx": ("edx", 0, 16), "edx": ("edx", 0, 32),
            "bl": ("ebx", 0, 8), "bh": ("ebx", 8, 8), "bx": ("ebx", 0, 16), "ebx": ("ebx", 0, 32),
            "sp": ("esp", 0, 16), "esp": ("esp", 0, 32), "bp": ("ebp", 0, 16), "ebp": ("ebp", 0, 32),
            "si": ("esi", 0, 16), "esi": ("esi", 0, 32), "di": ("edi", 0, 16), "edi": ("edi", 0, 32),
        }
        if name not in mapping:
            raise PEFormatError(f"Unsupported generated integer register {name}")
        return mapping[name]

    def register_read(self, name: str) -> str:
        segments = {"cs": "UINT32_C(0x1B)", "ds": "UINT32_C(0x23)", "es": "UINT32_C(0x23)", "ss": "UINT32_C(0x23)", "fs": "UINT32_C(0x3B)", "gs": "UINT32_C(0)"}
        if name in segments:
            return segments[name]
        storage, shift, width = self._register_storage(name)
        if width == 32:
            return f"cpu->{storage}"
        mask = "UINT32_C(0xFF)" if width == 8 else "UINT32_C(0xFFFF)"
        return f"((cpu->{storage} >> {shift}u) & {mask})" if shift else f"(cpu->{storage} & {mask})"

    def register_write(self, name: str, value: str) -> str:
        if name in {"cs", "ds", "es", "ss", "fs", "gs"}:
            return f"(void)({value});"
        storage, shift, width = self._register_storage(name)
        if width == 32:
            return f"cpu->{storage} = (uint32_t)({value});"
        if width == 16:
            return f"cpu->{storage} = (cpu->{storage} & UINT32_C(0xFFFF0000)) | ((uint32_t)({value}) & UINT32_C(0xFFFF));"
        if shift == 8:
            return f"cpu->{storage} = (cpu->{storage} & UINT32_C(0xFFFF00FF)) | (((uint32_t)({value}) & UINT32_C(0xFF)) << 8u);"
        return f"cpu->{storage} = (cpu->{storage} & UINT32_C(0xFFFFFF00)) | ((uint32_t)({value}) & UINT32_C(0xFF));"

    def effective_address(self, operand: DecodedOperand) -> str:
        terms: list[str] = []
        if operand.base:
            terms.append(self.register_read(operand.base))
        if operand.index:
            index = self.register_read(operand.index)
            terms.append(index if operand.scale == 1 else f"((uint32_t)({index}) * {operand.scale}u)")
        displacement = operand.displacement & 0xFFFFFFFF
        if operand.image_address:
            terms.append(f"lift_image_va({u32(displacement)})")
        elif displacement or not terms:
            terms.append(u32(displacement))
        return f"((uint32_t)({' + '.join(terms)}))"

    def read(self, operand: DecodedOperand) -> str:
        if operand.kind == "register":
            if not operand.reg:
                raise PEFormatError("Decoded register operand has no register")
            return self.register_read(operand.reg)
        if operand.kind in {"immediate", "branch"}:
            value = operand.imm or 0
            return f"lift_image_va({u32(value)})" if operand.image_address else u32(value)
        if operand.kind == "memory":
            if operand.width not in {8, 16, 32, 64}:
                raise PEFormatError(f"Unsupported integer memory width {operand.width}")
            prefix = "lift_fs_load" if operand.segment == "fs" else "lift_load"
            return f"{prefix}{operand.width}(cpu, {self.effective_address(operand)})" if operand.segment == "fs" else f"{prefix}{operand.width}({self.effective_address(operand)})"
        raise PEFormatError(f"Unsupported decoded operand kind {operand.kind}")

    def write(self, operand: DecodedOperand, value: str) -> str:
        if operand.kind == "register":
            if not operand.reg:
                raise PEFormatError("Decoded register destination has no register")
            return self.register_write(operand.reg, value)
        if operand.kind == "memory":
            if operand.width not in {8, 16, 32, 64}:
                raise PEFormatError(f"Unsupported integer memory width {operand.width}")
            prefix = "lift_fs_store" if operand.segment == "fs" else "lift_store"
            cast = {8: "uint8_t", 16: "uint16_t", 32: "uint32_t", 64: "uint64_t"}[operand.width]
            if operand.segment == "fs":
                return f"{prefix}{operand.width}(cpu, {self.effective_address(operand)}, ({cast})({value}));"
            return f"{prefix}{operand.width}({self.effective_address(operand)}, ({cast})({value}));"
        raise PEFormatError("Generated instruction writes a non-writable operand")

    @staticmethod
    def _signed_expression(value: str, width: int) -> str:
        signed_type = {8: "int8_t", 16: "int16_t", 32: "int32_t", 64: "int64_t"}.get(width)
        if not signed_type:
            raise PEFormatError(f"Unsupported signed width {width}")
        return f"(({signed_type})({value}))"

    @staticmethod
    def _set_flag(flag_name: str, condition: str) -> str:
        return f"cpu->eflags = (cpu->eflags & ~{flag_name}) | (({condition}) ? {flag_name} : 0u);"

    def condition(self, mnemonic: str) -> str:
        if mnemonic.startswith("cmov"):
            suffix = mnemonic[4:]
        elif mnemonic.startswith("set"):
            suffix = mnemonic[3:]
        elif mnemonic.startswith("j"):
            suffix = mnemonic[1:]
        else:
            raise PEFormatError(f"Opcode {mnemonic} is not conditional")
        if suffix not in _CONDITIONS:
            raise PEFormatError(f"Unsupported condition code {mnemonic}")
        return _CONDITIONS[suffix]

    def _float_read(self, operand: DecodedOperand) -> str:
        if operand.kind == "register" and operand.reg and operand.reg.startswith("st"):
            return f"lift_x87_get(cpu, {int(operand.reg[2:])}u)"
        if operand.kind == "memory" and operand.width == 32:
            return f"((double)lift_load_f32({self.effective_address(operand)}))"
        if operand.kind == "memory" and operand.width == 64:
            return f"lift_load_f64({self.effective_address(operand)})"
        raise PEFormatError("Unsupported x87 floating operand")

    def _float_write(self, operand: DecodedOperand, value: str) -> str:
        if operand.kind == "register" and operand.reg and operand.reg.startswith("st"):
            return f"lift_x87_set(cpu, {int(operand.reg[2:])}u, {value});"
        if operand.kind == "memory" and operand.width == 32:
            return f"lift_store_f32({self.effective_address(operand)}, (float)({value}));"
        if operand.kind == "memory" and operand.width == 64:
            return f"lift_store_f64({self.effective_address(operand)}, (double)({value}));"
        raise PEFormatError("Unsupported x87 floating destination")

    def _emit_x87(self, instruction: DecodedInstruction) -> list[str] | None:
        mnemonic = instruction.mnemonic
        operands = instruction.operands
        if mnemonic == "fld":
            return [f"lift_x87_push(cpu, {self._float_read(operands[0])});"]
        if mnemonic == "fld1":
            return ["lift_x87_push(cpu, 1.0);"]
        if mnemonic == "fldz":
            return ["lift_x87_push(cpu, 0.0);"]
        if mnemonic == "fild":
            source = self._signed_expression(self.read(operands[0]), operands[0].width)
            return [f"lift_x87_push(cpu, (double)({source}));"]
        if mnemonic in {"fst", "fstp"}:
            lines = [self._float_write(operands[0], "lift_x87_get(cpu, 0u)")]
            if mnemonic == "fstp":
                lines.append("lift_x87_pop(cpu);")
            return lines
        if mnemonic in {"fist", "fistp", "fisttp"}:
            value = f"lift_x87_round(cpu, lift_x87_get(cpu, 0u), {1 if mnemonic == 'fisttp' else 0}u)"
            lines = [self.write(operands[0], value)]
            if mnemonic != "fist":
                lines.append("lift_x87_pop(cpu);")
            return lines
        if mnemonic == "fxch":
            source = operands[1] if len(operands) >= 2 else operands[0]
            if not source.reg or not source.reg.startswith("st"):
                raise PEFormatError("FXCH does not name an x87 register")
            index = int(source.reg[2:])
            return [f"{{ double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, {index}u)); lift_x87_set(cpu, {index}u, temporary); }}"]
        if mnemonic == "fabs":
            return ["lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));"]
        if mnemonic == "fchs":
            return ["lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));"]
        if mnemonic == "fldcw":
            return [f"cpu->fpu_control = (uint16_t)({self.read(operands[0])});"]
        if mnemonic == "fnstcw":
            return [self.write(operands[0], "cpu->fpu_control")]
        if mnemonic == "fnstsw":
            return [self.write(operands[0], "(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))")]
        if mnemonic in {"fcom", "fcomp", "fucomp"}:
            source = operands[1] if len(operands) >= 2 else operands[0]
            lines = [f"lift_x87_compare(cpu, lift_x87_get(cpu, 0u), {self._float_read(source)});"]
            if mnemonic != "fcom":
                lines.append("lift_x87_pop(cpu);")
            return lines
        if mnemonic in {"fcompp", "fucompp"}:
            return ["lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));", "lift_x87_pop(cpu);", "lift_x87_pop(cpu);"]
        if mnemonic == "fsincos":
            return ["lift_x87_sincos(cpu);"]
        if mnemonic not in _X87_ARITHMETIC:
            return None
        integer_source = mnemonic.startswith("fi")
        pop = mnemonic.endswith("p") and not integer_source
        if integer_source:
            destination_index = 0
            source = f"(double)({self._signed_expression(self.read(operands[0]), operands[0].width)})"
        elif len(operands) >= 2:
            if not operands[0].reg or not operands[0].reg.startswith("st"):
                raise PEFormatError(f"{mnemonic} has a non-x87 destination")
            destination_index = int(operands[0].reg[2:])
            source = self._float_read(operands[1])
        else:
            destination_index = 0
            source = self._float_read(operands[0])
        destination = f"lift_x87_get(cpu, {destination_index}u)"
        if mnemonic in {"fadd", "faddp", "fiadd"}:
            expression = f"({destination}) + ({source})"
        elif mnemonic in {"fmul", "fmulp", "fimul"}:
            expression = f"({destination}) * ({source})"
        elif mnemonic in {"fsub", "fsubp", "fisub"}:
            expression = f"({destination}) - ({source})"
        elif mnemonic in {"fsubr", "fsubrp", "fisubr"}:
            expression = f"({source}) - ({destination})"
        elif mnemonic in {"fdiv", "fdivp", "fidiv"}:
            expression = f"({destination}) / ({source})"
        else:
            expression = f"({source}) / ({destination})"
        lines = [f"lift_x87_set(cpu, {destination_index}u, {expression});"]
        if pop:
            lines.append("lift_x87_pop(cpu);")
        return lines

    def _direct_import(self, operand: DecodedOperand) -> int | None:
        if operand.kind != "memory" or operand.base is not None or operand.index is not None:
            return None
        return self.import_by_va.get(operand.displacement & 0xFFFFFFFF)

    def _transfer(self, target: int, body: set[int], stop: str, callsite: int) -> list[str]:
        if target in body:
            return [f"goto label_{target:08X};"]
        if target in self.function_seeds:
            return [f"{function_name(self.pe, target)}(cpu, {stop});", "return;"]
        return [f"lift_tail_indirect(cpu, {self.local_va(target)}, {stop}, {self.local_va(callsite)});", "return;"]

    def emit_instruction(self, function: RecoveredFunction, instruction: DecodedInstruction) -> tuple[list[str], bool]:
        mnemonic = instruction.mnemonic
        operands = instruction.operands
        body = self.function_bodies[function.seed]
        x87 = self._emit_x87(instruction)
        if x87 is not None:
            return x87, False
        if mnemonic in {"mov", "movzx"}:
            return [self.write(operands[0], self.read(operands[1]))], False
        if mnemonic == "movsx":
            value = self._signed_expression(self.read(operands[1]), operands[1].width)
            return [self.write(operands[0], value)], False
        if mnemonic == "lea":
            return [self.write(operands[0], self.effective_address(operands[1]))], False
        if mnemonic in {"add", "adc", "sub", "sbb", "cmp", "and", "or", "xor", "test"}:
            width = operands[0].width
            left = self.read(operands[0])
            right = self.read(operands[1])
            lines = ["{", f"    uint64_t left = (uint64_t)({left});", f"    uint64_t right = (uint64_t)({right});"]
            if mnemonic in {"add", "adc"}:
                carry = "((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)" if mnemonic == "adc" else "0u"
                lines.extend([f"    uint64_t carry = {carry};", "    uint64_t result = left + right + carry;", f"    lift_flags_add(cpu, left, right, carry, result, {width}u);"])
                lines.append("    " + self.write(operands[0], "result"))
            elif mnemonic in {"sub", "sbb", "cmp"}:
                borrow = "((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)" if mnemonic == "sbb" else "0u"
                lines.extend([f"    uint64_t borrow = {borrow};", "    uint64_t result = left - right - borrow;", f"    lift_flags_sub(cpu, left, right, borrow, result, {width}u);"])
                if mnemonic != "cmp":
                    lines.append("    " + self.write(operands[0], "result"))
            else:
                operator = {"and": "&", "or": "|", "xor": "^", "test": "&"}[mnemonic]
                lines.extend([f"    uint64_t result = left {operator} right;", f"    lift_flags_logic(cpu, result, {width}u);"])
                if mnemonic != "test":
                    lines.append("    " + self.write(operands[0], "result"))
            lines.append("}")
            return lines, False
        if mnemonic in {"inc", "dec"}:
            width = operands[0].width
            operator = "+" if mnemonic == "inc" else "-"
            flag_function = "lift_flags_add" if mnemonic == "inc" else "lift_flags_sub"
            lines = ["{", f"    uint64_t left = (uint64_t)({self.read(operands[0])});", "    uint32_t saved_carry = cpu->eflags & LIFT_FLAG_CF;", f"    uint64_t result = left {operator} 1u;", f"    {flag_function}(cpu, left, 1u, 0u, result, {width}u);", "    cpu->eflags = (cpu->eflags & ~LIFT_FLAG_CF) | saved_carry;", "    " + self.write(operands[0], "result"), "}"]
            return lines, False
        if mnemonic == "neg":
            width = operands[0].width
            lines = ["{", f"    uint64_t value = (uint64_t)({self.read(operands[0])});", "    uint64_t result = 0u - value;", f"    lift_flags_sub(cpu, 0u, value, 0u, result, {width}u);", "    " + self._set_flag("LIFT_FLAG_CF", "value != 0u"), "    " + self.write(operands[0], "result"), "}"]
            return lines, False
        if mnemonic == "not":
            return [self.write(operands[0], f"~((uint64_t)({self.read(operands[0])}))")], False
        if mnemonic in {"shl", "sal", "shr", "sar", "rol", "ror", "rcl", "rcr"}:
            helper = {"shl": "lift_shift_left", "sal": "lift_shift_left", "shr": "lift_shift_right", "sar": "lift_shift_arithmetic", "rol": "lift_rotate_left", "ror": "lift_rotate_right", "rcl": "lift_rotate_carry_left", "rcr": "lift_rotate_carry_right"}[mnemonic]
            value = self.read(operands[0])
            count = self.read(operands[1])
            return [self.write(operands[0], f"{helper}(cpu, {value}, (uint32_t)({count}), {operands[0].width}u)")], False
        if mnemonic in {"shld", "shrd"}:
            helper = "lift_double_shift_left" if mnemonic == "shld" else "lift_double_shift_right"
            expression = f"{helper}(cpu, {self.read(operands[0])}, {self.read(operands[1])}, (uint32_t)({self.read(operands[2])}), {operands[0].width}u)"
            return [self.write(operands[0], expression)], False
        if mnemonic == "imul":
            if len(operands) == 1:
                return [f"lift_multiply_accumulator(cpu, {self.read(operands[0])}, {operands[0].width}u, 1u);"], False
            source = operands[-1]
            left_operand = operands[0] if len(operands) == 2 else operands[1]
            left = self._signed_expression(self.read(left_operand), source.width)
            right = self._signed_expression(self.read(source), source.width)
            signed_destination = {8: "int8_t", 16: "int16_t", 32: "int32_t", 64: "int64_t"}[operands[0].width]
            lines = ["{", f"    int64_t result = (int64_t)({left}) * (int64_t)({right});", "    " + self.write(operands[0], "(uint64_t)result"), f"    int64_t truncated = (int64_t)({signed_destination})result;", "    uint32_t overflow = truncated != result;", "    " + self._set_flag("LIFT_FLAG_CF", "overflow != 0u"), "    " + self._set_flag("LIFT_FLAG_OF", "overflow != 0u"), "}"]
            return lines, False
        if mnemonic == "mul":
            return [f"lift_multiply_accumulator(cpu, {self.read(operands[0])}, {operands[0].width}u, 0u);"], False
        if mnemonic in {"idiv", "div"}:
            return [f"lift_divide_accumulator(cpu, {self.read(operands[0])}, {operands[0].width}u, {1 if mnemonic == 'idiv' else 0}u);"], False
        if mnemonic == "cdq":
            return ["cpu->edx = ((int32_t)cpu->eax < 0) ? UINT32_C(0xFFFFFFFF) : 0u;"], False
        if mnemonic == "cwde":
            return ["cpu->eax = (uint32_t)(int32_t)(int16_t)cpu->eax;"], False
        if mnemonic == "push":
            return [f"lift_push32(cpu, (uint32_t)({self.read(operands[0])}));"], False
        if mnemonic == "pop":
            return [self.write(operands[0], "lift_pop32(cpu)")], False
        if mnemonic == "pushfd":
            return ["lift_push32(cpu, cpu->eflags);"], False
        if mnemonic == "popfd":
            return ["cpu->eflags = lift_pop32(cpu) | 2u;"], False
        if mnemonic == "pushad":
            return ["{ uint32_t original_esp = cpu->esp; lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, original_esp); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); }"], False
        if mnemonic == "popad":
            return ["cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->ebx = lift_pop32(cpu); cpu->edx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->eax = lift_pop32(cpu);"], False
        if mnemonic == "xchg":
            lines = ["{", f"    uint64_t left = {self.read(operands[0])};", f"    uint64_t right = {self.read(operands[1])};", "    " + self.write(operands[0], "right"), "    " + self.write(operands[1], "left"), "}"]
            return lines, False
        if mnemonic == "call":
            next_address = self.local_va(instruction.next_rva)
            callsite = self.local_va(instruction.rva)
            target = instruction.branch_target_rva
            if instruction.rva == self.unsigned_decimal_callsite_rva and target == self.unsigned_decimal_rva:
                return ["sfera_u32_to_sso_decimal(cpu);", f"cpu->eip = {next_address};"], False
            if target in self.function_seeds:
                return [f"lift_push32(cpu, {next_address});", f"{function_name(self.pe, target)}(cpu, {next_address});", f"if (cpu->eip != {next_address}) {{ return; }}"], False
            import_index = self._direct_import(operands[0])
            if import_index is not None:
                return [f"{self.import_symbols[import_index]}(cpu, {callsite});", f"cpu->eip = {next_address};"], False
            return [f"if (!lift_call_indirect(cpu, (uint32_t)({self.read(operands[0])}), {next_address}, {callsite})) {{ return; }}"], False
        if mnemonic == "jmp":
            if instruction.branch_target_rva is not None:
                return self._transfer(instruction.branch_target_rva, body, "stop_address", instruction.rva), True
            import_index = self._direct_import(operands[0])
            if import_index is not None:
                lines = ["{", "    uint32_t return_address = lift_pop32(cpu);", f"    {self.import_symbols[import_index]}(cpu, {self.local_va(instruction.rva)});", "    cpu->eip = return_address;", "    if (return_address != stop_address) { lift_dispatch(cpu, return_address, stop_address); }", "    return;", "}"]
                return lines, True
            targets = self.recovery.switch_targets.get(instruction.rva, ())
            if targets:
                lines = ["{", f"    uint32_t target = (uint32_t)({self.read(operands[0])});", f"    switch (target - {self.local_va(0)}) {{"]
                for target in targets:
                    if target in body:
                        lines.append(f"        case 0x{target:08X}u: goto label_{target:08X};")
                lines.extend([f"        default: lift_tail_indirect(cpu, target, stop_address, {self.local_va(instruction.rva)}); return;", "    }", "}"])
                return lines, True
            return [f"lift_tail_indirect(cpu, (uint32_t)({self.read(operands[0])}), stop_address, {self.local_va(instruction.rva)});", "return;"], True
        if mnemonic == "ret":
            cleanup = (operands[0].imm or 0) & 0xFFFF if operands else 0
            return [f"lift_return(cpu, {cleanup}u, stop_address);", "return;"], True
        if mnemonic == "leave":
            return ["cpu->esp = cpu->ebp;", "cpu->ebp = lift_pop32(cpu);"], False
        if mnemonic.startswith("j") and mnemonic[1:] in _CONDITIONS:
            target = instruction.branch_target_rva
            if target is None:
                raise PEFormatError(f"Conditional branch has no local target at 0x{self.source_va(instruction.rva):08X}")
            condition = self.condition(mnemonic)
            transfer = self._transfer(target, body, "stop_address", instruction.rva)
            if len(transfer) == 1:
                return [f"if ({condition}) {{ {transfer[0]} }}"], False
            return [f"if ({condition}) {{", *("    " + line for line in transfer), "}"], False
        if mnemonic in {"jecxz", "jcxz"}:
            target = instruction.branch_target_rva
            condition = "cpu->ecx == 0u" if mnemonic == "jecxz" else "(cpu->ecx & UINT32_C(0xFFFF)) == 0u"
            transfer = self._transfer(target or 0, body, "stop_address", instruction.rva)
            return [f"if ({condition}) {{", *("    " + line for line in transfer), "}"], False
        if mnemonic in {"loop", "loope", "loopne"}:
            target = instruction.branch_target_rva or 0
            condition = "cpu->ecx != 0u"
            if mnemonic == "loope":
                condition += " && (cpu->eflags & LIFT_FLAG_ZF) != 0u"
            elif mnemonic == "loopne":
                condition += " && (cpu->eflags & LIFT_FLAG_ZF) == 0u"
            transfer = self._transfer(target, body, "stop_address", instruction.rva)
            return ["cpu->ecx -= 1u;", f"if ({condition}) {{", *("    " + line for line in transfer), "}"], False
        if mnemonic.startswith("set") and mnemonic[3:] in _CONDITIONS:
            return [self.write(operands[0], f"({self.condition(mnemonic)}) ? 1u : 0u")], False
        if mnemonic.startswith("cmov") and mnemonic[4:] in _CONDITIONS:
            return [f"if ({self.condition(mnemonic)}) {{ {self.write(operands[0], self.read(operands[1]))} }}"], False
        if mnemonic in {"clc", "stc", "cmc", "cld", "std"}:
            if mnemonic == "clc":
                return ["cpu->eflags &= ~LIFT_FLAG_CF;"], False
            if mnemonic == "stc":
                return ["cpu->eflags |= LIFT_FLAG_CF;"], False
            if mnemonic == "cmc":
                return ["cpu->eflags ^= LIFT_FLAG_CF;"], False
            if mnemonic == "cld":
                return ["cpu->eflags &= ~LIFT_FLAG_DF;"], False
            return ["cpu->eflags |= LIFT_FLAG_DF;"], False
        if mnemonic == "lahf":
            return [self.register_write("ah", "(cpu->eflags & UINT32_C(0xD5)) | 2u")], False
        if mnemonic == "sahf":
            return ["cpu->eflags = (cpu->eflags & ~UINT32_C(0xD5)) | ((cpu->eax >> 8u) & UINT32_C(0xD5)) | 2u;"], False
        if mnemonic in {"movsb", "movsw", "movsd"}:
            if not (len(operands) == 2 and operands[0].kind == "memory" and operands[1].kind == "memory"):
                raise PEFormatError(f"SIMD {mnemonic} requires a dedicated lowering rule")
            width = {"movsb": 8, "movsw": 16, "movsd": 32}[mnemonic]
            return [f"lift_movs{width}(cpu, {1 if instruction.rep else 0}u);"], False
        if mnemonic in {"stosb", "stosw", "stosd"}:
            width = {"stosb": 8, "stosw": 16, "stosd": 32}[mnemonic]
            return [f"lift_stos{width}(cpu, {1 if instruction.rep else 0}u);"], False
        if mnemonic in {"cmpsb", "cmpsw", "cmpsd", "scasb", "scasw", "scasd"}:
            width = 8 if mnemonic.endswith("b") else 16 if mnemonic.endswith("w") else 32
            helper = "lift_cmps" if mnemonic.startswith("cmps") else "lift_scas"
            repeated = instruction.rep or instruction.repe or instruction.repne
            return [f"{helper}{width}(cpu, {1 if repeated else 0}u, {1 if instruction.repne else 0}u);"], False
        if mnemonic == "cvttsd2si":
            source = operands[1]
            if source.kind == "memory" and source.width == 64:
                value = f"lift_load_f64({self.effective_address(source)})"
            else:
                raise PEFormatError("CVTTSD2SI requires unsupported XMM lowering")
            return [self.write(operands[0], f"(uint32_t)(int32_t)trunc({value})")], False
        if mnemonic in {"nop", "wait"}:
            return ["(void)cpu;"], False
        if mnemonic == "int3":
            return [f"lift_trap(cpu, {u32(self.source_va(instruction.rva))}, \"INT3\");", "return;"], True
        raise PEFormatError(f"No native C lowering rule for {mnemonic} at 0x{self.source_va(instruction.rva):08X}: {instruction.text}")

    def emit_function(self, function: RecoveredFunction) -> str:
        body = self.function_bodies[function.seed]
        if function.seed not in body:
            raise PEFormatError(f"Recovered function entry 0x{self.source_va(function.seed):08X} is absent from its body")
        label_targets: set[int] = {function.seed}
        for item in function.instructions:
            if item.flow in {"conditional_branch", "unconditional_branch"} and item.branch_target_rva in body:
                label_targets.add(item.branch_target_rva)
            label_targets.update(target for target in self.recovery.switch_targets.get(item.rva, ()) if target in body)
        lines = [f"void LIFT_CDECL {function_name(self.pe, function.seed)}(LiftCpu* cpu, uint32_t stop_address) {{", "    (void)stop_address;", f"    goto label_{function.seed:08X};"]
        for index, instruction in enumerate(function.instructions):
            if instruction.rva in label_targets:
                lines.append(f"label_{instruction.rva:08X}: ;")
            if instruction.rva in function.leaders:
                lines.append(f"    lift_enter_block(cpu, {u32(self.source_va(instruction.rva))});")
            lines.append(f"    /* {self.source_va(instruction.rva):08X}: {instruction.text} */")
            emitted, terminated = self.emit_instruction(function, instruction)
            lines.extend("    " + line for line in emitted)
            if terminated:
                continue
            next_rva = instruction.next_rva
            sequential = index + 1 < len(function.instructions) and function.instructions[index + 1].rva == next_rva
            if sequential:
                continue
            lines.extend("    " + line for line in self._transfer(next_rva, body, "stop_address", instruction.rva))
        lines.extend(["    lift_trap(cpu, cpu->eip, \"function fell through without control transfer\");", "}", ""])
        return "\n".join(lines)

    def emit_functions(self, output: Path, instructions_per_file: int = 12_000) -> list[str]:
        names: list[str] = []
        chunk: list[str] = []
        chunk_instructions = 0
        chunk_index = 0
        for function in self.recovery.functions:
            if function.seed == self.config_lookup_rva:
                continue
            rendered = self.emit_function(function)
            if chunk and chunk_instructions + len(function.instructions) > instructions_per_file:
                filename = f"lifted_functions_{chunk_index:03d}.c"
                (output / filename).write_text("#include \"lifted_functions.h\"\n\n#include <math.h>\n\n" + "\n".join(chunk), encoding="utf-8", newline="\n")
                names.append(filename)
                chunk = []
                chunk_instructions = 0
                chunk_index += 1
            chunk.append(rendered)
            chunk_instructions += len(function.instructions)
        if chunk:
            filename = f"lifted_functions_{chunk_index:03d}.c"
            (output / filename).write_text("#include \"lifted_functions.h\"\n\n#include <math.h>\n\n" + "\n".join(chunk), encoding="utf-8", newline="\n")
            names.append(filename)
        return names

    def emit_semantics(self, output: Path) -> str | None:
        if self.config_lookup_rva is None and self.unsigned_decimal_rva is None:
            return None
        lines = ["#include \"lifted_functions.h\"", "", "#include <stddef.h>", "#include <stdint.h>", ""]
        if self.config_lookup_rva is not None:
            source_target = self.summaries.config_lookup_target
            pointer_address = self.summaries.config_text_pointer_address
            length_address = self.summaries.config_text_length_address
            capacity = self.summaries.config_text_capacity
            lines.extend([
                "static uint32_t sfera_config_lookup(uint32_t key_address) {",
                f"    const uint32_t text_address = lift_load32(lift_image_va({u32(pointer_address)}));",
                f"    const uint32_t text_length = lift_load32(lift_image_va({u32(length_address)}));",
                "    if (text_address == 0u || key_address == 0u) { return 0u; }",
                "    size_t key_length = 0u;",
                "    while (key_length != 4096u && lift_load8(key_address + (uint32_t)key_length) != 0u) { ++key_length; }",
                "    if (key_length == 4096u) { return 0u; }",
                f"    const size_t bounded_length = text_length < {u32(capacity)} ? (size_t)text_length : (size_t){u32(capacity)};",
                "    const size_t scan_limit = bounded_length + 1u;",
                "    if ((uint64_t)text_address + (uint64_t)scan_limit > UINT64_C(0x100000000)) { return 0u; }",
                "    size_t line = 0u;",
                "    while (line < scan_limit) {",
                "        size_t token_end = line;",
                "        while (token_end < scan_limit) {",
                "            const uint8_t value = lift_load8(text_address + (uint32_t)token_end);",
                "            if (value == (uint8_t)' ' || value == (uint8_t)'\\t' || value == (uint8_t)'\\r' || value == 0u) { break; }",
                "            ++token_end;",
                "        }",
                "        int matches = token_end - line == key_length;",
                "        for (size_t index = 0u; matches && index != key_length; ++index) {",
                "            matches = lift_load8(text_address + (uint32_t)(line + index)) == lift_load8(key_address + (uint32_t)index);",
                "        }",
                "        if (matches) {",
                "            size_t value = token_end;",
                "            while (value < scan_limit) {",
                "                const uint8_t current = lift_load8(text_address + (uint32_t)value);",
                "                if (current != (uint8_t)' ' && current != (uint8_t)'\\t') { break; }",
                "                ++value;",
                "            }",
                "            return value < scan_limit ? text_address + (uint32_t)value : 0u;",
                "        }",
                "        size_t next_line = token_end;",
                "        while (next_line < scan_limit) {",
                "            const uint8_t current = lift_load8(text_address + (uint32_t)next_line);",
                "            if (current == (uint8_t)'\\n' || current == 0u) { break; }",
                "            ++next_line;",
                "        }",
                "        if (next_line == scan_limit || lift_load8(text_address + (uint32_t)next_line) == 0u) { return 0u; }",
                "        line = next_line + 1u;",
                "    }",
                "    return 0u;",
                "}",
                "",
                f"void LIFT_CDECL {function_name(self.pe, self.config_lookup_rva)}(LiftCpu* cpu, uint32_t stop_address) {{",
                "    (void)stop_address;",
                f"    goto label_{self.config_lookup_rva:08X};",
                f"label_{self.config_lookup_rva:08X}: ;",
                f"    lift_enter_block(cpu, {u32(source_target)});",
                "    const uint32_t key_address = lift_load32(cpu->esp + 4u);",
                "    cpu->eax = sfera_config_lookup(key_address);",
                "    lift_note_config_lookup(key_address, cpu->eax);",
                "    lift_return(cpu, 4u, stop_address);",
                "}",
                "",
            ])
        if self.unsigned_decimal_rva is not None:
            lines.extend([
                "void LIFT_CDECL sfera_u32_to_sso_decimal(LiftCpu* cpu) {",
                "    const uint32_t destination = cpu->ecx;",
                "    uint32_t value = lift_load32(cpu->edx);",
                "    uint8_t reversed[16];",
                "    size_t length = 0u;",
                "    do {",
                "        reversed[length++] = (uint8_t)('0' + value % 10u);",
                "        value /= 10u;",
                "    } while (value != 0u);",
                "    for (size_t index = 0u; index != 16u; ++index) {",
                "        const uint8_t output = index < length ? reversed[length - index - 1u] : 0u;",
                "        lift_store8(destination + (uint32_t)index, output);",
                "    }",
                "    lift_store32(destination + 0x10u, (uint32_t)length);",
                "    lift_store32(destination + 0x14u, 15u);",
                "    cpu->eax = destination;",
                "}",
                "",
            ])
        name = "lifted_functions_semantics.c"
        (output / name).write_text("\n".join(lines), encoding="utf-8", newline="\n")
        return name

    def emit_function_header(self, output: Path) -> None:
        declarations = [f"void LIFT_CDECL {function_name(self.pe, function.seed)}(LiftCpu* cpu, uint32_t stop_address);" for function in self.recovery.functions]
        if self.unsigned_decimal_rva is not None:
            declarations.append("void LIFT_CDECL sfera_u32_to_sso_decimal(LiftCpu* cpu);")
        imports = [f"void LIFT_CDECL {name}(LiftCpu* cpu, uint32_t callsite);" for name in self.import_symbols]
        content = "\n".join(["#pragma once", "", "#include \"lifted_abi.h\"", "", "#ifdef __cplusplus", "extern \"C\" {", "#endif", "", *declarations, "", *imports, "", "#ifdef __cplusplus", "}", "#endif", ""])
        output.write_text(content, encoding="utf-8", newline="\n")

    def emit_imports(self, output: Path) -> str:
        rows = [f"void LIFT_CDECL {name}(LiftCpu* cpu, uint32_t callsite) {{ lift_import_call(cpu, {index}u, callsite); }}" for index, name in enumerate(self.import_symbols)]
        name = "lifted_imports.c"
        (output / name).write_text("#include \"lifted_functions.h\"\n\n" + "\n".join(rows) + "\n", encoding="utf-8", newline="\n")
        return name

    def emit_dispatch(self, output: Path) -> str:
        entries = [f"    {{0x{function.seed:08X}u, &{function_name(self.pe, function.seed)}}}," for function in self.recovery.functions]
        content = f'''#include "lifted_functions.h"

#include <stddef.h>

typedef struct LiftFunctionEntry {{ uint32_t rva; LiftFunction function; }} LiftFunctionEntry;

static const LiftFunctionEntry kLiftedFunctions[{len(entries)}] = {{
{chr(10).join(entries)}
}};

static LiftFunction resolve_lifted_function(uint32_t target) {{
    uint32_t base = lift_image_va({u32(self.pe.image_base)});
    if (target < base || (uint64_t)(target - base) >= UINT64_C(0x{self.pe.size_of_image:X})) {{ return (LiftFunction)0; }}
    uint32_t rva = target - base;
    size_t first = 0u;
    size_t count = sizeof(kLiftedFunctions) / sizeof(kLiftedFunctions[0]);
    while (count != 0u) {{
        size_t step = count / 2u;
        size_t middle = first + step;
        if (kLiftedFunctions[middle].rva < rva) {{ first = middle + 1u; count -= step + 1u; }} else {{ count = step; }}
    }}
    return first < sizeof(kLiftedFunctions) / sizeof(kLiftedFunctions[0]) && kLiftedFunctions[first].rva == rva ? kLiftedFunctions[first].function : (LiftFunction)0;
}}

static int target_is_local(uint32_t target) {{
    uint32_t base = lift_image_va({u32(self.pe.image_base)});
    return target >= base && (uint64_t)(target - base) < UINT64_C(0x{self.pe.size_of_image:X});
}}

void LIFT_CDECL lift_dispatch(LiftCpu* cpu, uint32_t target, uint32_t stop_address) {{
    LiftFunction function = resolve_lifted_function(target);
    if (!function) {{
        uint32_t base = lift_image_va({u32(self.pe.image_base)});
        uint32_t source = target_is_local(target) ? {u32(self.pe.image_base)} + (target - base) : {u32(self.pe.image_base)};
        lift_trap(cpu, source, "unresolved native C function target");
    }}
    cpu->eip = target;
    function(cpu, stop_address);
}}

int LIFT_CDECL lift_call_indirect(LiftCpu* cpu, uint32_t target, uint32_t return_address, uint32_t callsite) {{
    LiftFunction function = resolve_lifted_function(target);
    if (function) {{
        lift_push32(cpu, return_address);
        function(cpu, return_address);
        return cpu->eip == return_address;
    }}
    if (target_is_local(target)) {{
        uint32_t base = lift_image_va({u32(self.pe.image_base)});
        lift_trap(cpu, {u32(self.pe.image_base)} + (target - base), "indirect call targets the middle of no recovered function");
    }}
    lift_native_call(cpu, target, callsite);
    cpu->eip = return_address;
    return 1;
}}

void LIFT_CDECL lift_tail_indirect(LiftCpu* cpu, uint32_t target, uint32_t stop_address, uint32_t callsite) {{
    LiftFunction function = resolve_lifted_function(target);
    if (function) {{ function(cpu, stop_address); return; }}
    if (target_is_local(target)) {{
        uint32_t base = lift_image_va({u32(self.pe.image_base)});
        lift_trap(cpu, {u32(self.pe.image_base)} + (target - base), "indirect jump targets the middle of no recovered function");
    }}
    uint32_t return_address = lift_pop32(cpu);
    lift_native_call(cpu, target, callsite);
    cpu->eip = return_address;
    if (return_address != stop_address) {{ lift_dispatch(cpu, return_address, stop_address); }}
}}

void LIFT_CDECL lift_return(LiftCpu* cpu, uint32_t stack_cleanup, uint32_t stop_address) {{
    uint32_t target = lift_pop32(cpu);
    cpu->esp += stack_cleanup;
    cpu->eip = target;
    if (target != stop_address) {{ lift_dispatch(cpu, target, stop_address); }}
}}
'''
        name = "lifted_dispatch.c"
        (output / name).write_text(content, encoding="utf-8", newline="\n")
        return name


def emit_vcxproj(project_name: str, target_name: str, dll_names: list[str], c_sources: list[str], output: Path) -> None:
    copies = "&#xD;&#xA;".join(f'copy /Y "$(ProjectDir)..\\{name}" "$(OutDir){name}" &gt;nul' for name in dll_names)
    c_rows = "".join(f'<ClCompile Include="{name}"><CompileAs>CompileAsC</CompileAs></ClCompile>' for name in c_sources)
    content = f'''<?xml version="1.0" encoding="utf-8"?>
<Project DefaultTargets="Build" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup Label="ProjectConfigurations"><ProjectConfiguration Include="Debug|Win32"><Configuration>Debug</Configuration><Platform>Win32</Platform></ProjectConfiguration><ProjectConfiguration Include="Release|Win32"><Configuration>Release</Configuration><Platform>Win32</Platform></ProjectConfiguration></ItemGroup>
  <PropertyGroup Label="Globals"><ProjectGuid>{{A39E9674-6287-43D1-893D-8D27E20E8064}}</ProjectGuid><Keyword>Win32Proj</Keyword><RootNamespace>{project_name}</RootNamespace><WindowsTargetPlatformVersion>10.0</WindowsTargetPlatformVersion></PropertyGroup>
  <Import Project="$(VCTargetsPath)\\Microsoft.Cpp.Default.props" />
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'" Label="Configuration"><ConfigurationType>Application</ConfigurationType><UseDebugLibraries>true</UseDebugLibraries><PlatformToolset>v143</PlatformToolset><CharacterSet>Unicode</CharacterSet></PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'" Label="Configuration"><ConfigurationType>Application</ConfigurationType><UseDebugLibraries>false</UseDebugLibraries><PlatformToolset>v143</PlatformToolset><WholeProgramOptimization>true</WholeProgramOptimization><CharacterSet>Unicode</CharacterSet></PropertyGroup>
  <Import Project="$(VCTargetsPath)\\Microsoft.Cpp.props" />
  <PropertyGroup><TargetName>{target_name}</TargetName></PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'"><OutDir>$(ProjectDir)bin\\Debug\\</OutDir><IntDir>$(ProjectDir)obj\\Debug\\</IntDir><LocalDebuggerWorkingDirectory>$(ProjectDir)..\\</LocalDebuggerWorkingDirectory><LocalDebuggerCommandArguments>/login</LocalDebuggerCommandArguments><DebuggerFlavor>WindowsLocalDebugger</DebuggerFlavor></PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'"><OutDir>$(ProjectDir)bin\\Release\\</OutDir><IntDir>$(ProjectDir)obj\\Release\\</IntDir><LocalDebuggerWorkingDirectory>$(ProjectDir)..\\</LocalDebuggerWorkingDirectory><LocalDebuggerCommandArguments>/login</LocalDebuggerCommandArguments><DebuggerFlavor>WindowsLocalDebugger</DebuggerFlavor></PropertyGroup>
  <ItemDefinitionGroup><ClCompile><WarningLevel>Level4</WarningLevel><SDLCheck>true</SDLCheck><PreprocessorDefinitions>WIN32;UNICODE;_UNICODE;%(PreprocessorDefinitions)</PreprocessorDefinitions><ConformanceMode>true</ConformanceMode><LanguageStandard>stdcpp20</LanguageStandard><LanguageStandard_C>stdc17</LanguageStandard_C><MultiProcessorCompilation>true</MultiProcessorCompilation></ClCompile><Link><SubSystem>Windows</SubSystem><EnableCOMDATFolding>true</EnableCOMDATFolding><OptimizeReferences>true</OptimizeReferences><GenerateDebugInformation>true</GenerateDebugInformation><RandomizedBaseAddress>true</RandomizedBaseAddress><DataExecutionPrevention>true</DataExecutionPrevention><TargetMachine>MachineX86</TargetMachine></Link><PostBuildEvent><Command>{copies}</Command></PostBuildEvent></ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'"><ClCompile><Optimization>Disabled</Optimization><BasicRuntimeChecks>EnableFastChecks</BasicRuntimeChecks><RuntimeLibrary>MultiThreadedDebug</RuntimeLibrary></ClCompile></ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'"><ClCompile><Optimization>MaxSpeed</Optimization><InlineFunctionExpansion>AnySuitable</InlineFunctionExpansion><IntrinsicFunctions>true</IntrinsicFunctions><FunctionLevelLinking>true</FunctionLevelLinking><FavorSizeOrSpeed>Speed</FavorSizeOrSpeed><BasicRuntimeChecks>Default</BasicRuntimeChecks><RuntimeLibrary>MultiThreaded</RuntimeLibrary></ClCompile></ItemDefinitionGroup>
  <ItemGroup><ClCompile Include="diagnostics.cpp" /><ClCompile Include="main.cpp" /><ClCompile Include="runtime.cpp" />{c_rows}</ItemGroup>
  <ItemGroup><ClInclude Include="diagnostics.h" /><ClInclude Include="runtime.h" /><ClInclude Include="lifted_abi.h" /><ClInclude Include="lifted_functions.h" /><ClInclude Include="source.h" /></ItemGroup>
  <Import Project="$(VCTargetsPath)\\Microsoft.Cpp.targets" />
</Project>
'''
    output.write_text(content, encoding="utf-8", newline="\n")


def emit_solution(project_name: str, output: Path) -> None:
    output.write_text(f'''Microsoft Visual Studio Solution File, Format Version 12.00
# Visual Studio Version 17
VisualStudioVersion = 17.0.31903.59
MinimumVisualStudioVersion = 10.0.40219.1
Project("{{8BC9CEB8-8B4A-11D0-8D27E20E8064}}") = "{project_name}", "{project_name}.vcxproj", "{{A39E9674-6287-43D1-893D-8D27E20E8064}}"
EndProject
Global
    GlobalSection(SolutionConfigurationPlatforms) = preSolution
        Debug|x86 = Debug|x86
        Release|x86 = Release|x86
    EndGlobalSection
    GlobalSection(ProjectConfigurationPlatforms) = postSolution
        {{A39E9674-6287-43D1-893D-8D27E20E8064}}.Debug|x86.ActiveCfg = Debug|Win32
        {{A39E9674-6287-43D1-893D-8D27E20E8064}}.Debug|x86.Build.0 = Debug|Win32
        {{A39E9674-6287-43D1-893D-8D27E20E8064}}.Release|x86.ActiveCfg = Release|Win32
        {{A39E9674-6287-43D1-893D-8D27E20E8064}}.Release|x86.Build.0 = Release|Win32
    EndGlobalSection
EndGlobal
''', encoding="utf-8", newline="\n")


def emit_build_script(project_name: str, output: Path) -> None:
    output.write_text(f'''@echo off
setlocal
where msbuild >nul 2>nul
if errorlevel 1 (
    echo MSBuild was not found. Run this file from a Visual Studio 2022 Developer Command Prompt.
    exit /b 1
)
msbuild "{project_name}.sln" /t:Rebuild /m /p:Configuration=Release /p:Platform=x86
endlocal
''', encoding="utf-8", newline="\r\n")


def emit_readme(output: Path) -> None:
    output.write_text("""# Sfera — native C lift

Генератор восстанавливает функции PE32/x86 и поднимает каждую достижимую инструкцию в прямые выражения, присваивания, переходы и вызовы C17. Декодированные инструкции существуют только во время Python-анализа. В выходном проекте нет таблиц инструкций, opcode-dispatch или цикла интерпретации.

Прямые внутренние вызовы ссылаются на именованные `sfera_sub_*` функции. Вызовы через IAT ссылаются на именованные `sfera_import_*` мосты. Для function pointers и виртуальных вызовов используется таблица только восстановленных входов функций. Она разрешает адрес в C-функцию и не содержит инструкций или их семантики.

Каждая C-функция начинает работу с явного перехода на собственную восстановленную точку входа. Общие хвостовые блоки могут располагаться раньше неё по адресу, не меняя порядок исполнения.

Распознанные библиотечные идиомы нормализуются в отдельные C-функции. Построение `NEW_FONT_n` не использует `std::iostream`, а поиск значения в загруженном `.ui` выполняется ограниченным C-сканером с исходной очисткой стека. Генерация прекращается, если адреса хранилища или точка вызова определяются неоднозначно.

ABI сохраняет виртуальные x86-регистры, исходный стек, EFLAGS, x87, FS/TEB, cdecl/stdcall/thiscall/fastcall и callback-переходы. Образ данных релокируется в текущий Win32-процесс; исходные исполняемые секции обнулены, кроме восстановленных switch-таблиц, lookup-данных и пятибайтовых callback-стабов.

Сборка: запустите `build_release.cmd` из Visual Studio 2022 Developer Command Prompt с компонентом Desktop development with C++. Цель — Release/x86. Сводка восстановления и статических проверок находится в `report.json`.
""", encoding="utf-8", newline="\n")


def validate_native_output(output: Path) -> list[str]:
    forbidden = [
        "InstructionDescriptor",
        "OperandDescriptor",
        "InstructionChunk",
        "NativeOp",
        "execute_instruction",
        "execute_native",
        "kInstructionChunks",
        "Runtime::step",
        "while (!state.stopped)",
        "switch (instruction",
        "op_name(",
        "ir_data.h",
        "structured-IR",
        "structured IR",
    ]
    hits: list[str] = []
    for path in sorted(output.iterdir()):
        if path.suffix.lower() not in {".c", ".cpp", ".h"}:
            continue
        text = path.read_text(encoding="utf-8")
        for token in forbidden:
            if token in text:
                hits.append(f"{path.name}: {token}")
    if not any(output.glob("lifted_functions_*.c")):
        hits.append("no generated C function files")
    return hits


def validate_function_entry_guards(pe: PE32, recovery: Recovery, output: Path) -> list[str]:
    pattern = re.compile(r"void LIFT_CDECL (sfera_sub_[0-9A-F]{8})\(LiftCpu\* cpu, uint32_t stop_address\) \{\n    \(void\)stop_address;\n    goto label_([0-9A-F]{8});")
    actual: dict[str, str] = {}
    hits: list[str] = []
    for path in sorted(output.glob("lifted_functions_*.c")):
        for name, label in pattern.findall(path.read_text(encoding="utf-8")):
            if name in actual: hits.append(f"duplicate function entry guard: {name}")
            actual[name] = label
    for function in recovery.functions:
        name = function_name(pe, function.seed)
        expected = f"{function.seed:08X}"
        if actual.get(name) != expected: hits.append(f"invalid function entry guard: {name}, expected label_{expected}")
    return hits[:20]


def portable_c_syntax_check(output: Path, c_sources: list[str]) -> tuple[str | None, bool | None]:
    compiler = shutil.which("gcc") or shutil.which("clang")
    if compiler is None:
        return None, None
    command = [compiler, "-std=c17", "-Wall", "-Wextra", "-Werror", "-pedantic-errors", "-fsyntax-only", f"-I{output}"]
    command.extend(str(output / name) for name in c_sources)
    result = subprocess.run(command, capture_output=True, text=True, check=False)
    if result.returncode != 0:
        details = (result.stdout + result.stderr).strip()
        raise PEFormatError(f"Generated C failed strict syntax validation with {Path(compiler).name}:\n{details[-8000:]}")
    return Path(compiler).name, True


def portable_runtime_syntax_check(output: Path) -> tuple[str | None, bool | None]:
    compiler = shutil.which("g++") or shutil.which("clang++")
    if compiler is None:
        return None, None
    stub = Path(__file__).resolve().parent / "qa" / "portable_win32"
    command = [
        compiler,
        "-std=c++20",
        "-DSFERA_PORTABLE_CHECK",
        f"-I{stub}",
        f"-I{output}",
        "-Wall",
        "-Wextra",
        "-Werror",
        "-pedantic-errors",
        "-fsyntax-only",
        str(output / "runtime.cpp"),
        str(output / "diagnostics.cpp"),
        str(output / "main.cpp"),
    ]
    result = subprocess.run(command, capture_output=True, text=True, check=False)
    if result.returncode != 0:
        details = (result.stdout + result.stderr).strip()
        raise PEFormatError(f"Generated runtime failed portable syntax validation with {Path(compiler).name}:\n{details[-8000:]}")
    return Path(compiler).name, True


def generate(pe: PE32, root: Path, out: Path) -> None:
    started = time.perf_counter()
    if out.exists():
        shutil.rmtree(out)
    out.mkdir(parents=True)
    print("[decode] PE32/x86 control flow")
    program = decode_program(pe)
    recovery = recover_functions(pe, program)
    print(f"[functions] {len(recovery.functions):,} boundaries, {len(recovery.instructions):,} reachable instructions")
    summaries = discover_semantic_summaries(pe, program.instructions)
    print(f"[normalize] config={summaries.config_lookup_target:#010x}, decimal={summaries.unsigned_decimal_target:#010x} at {summaries.unsigned_decimal_callsite:#010x}")
    lowerer = CLowerer(pe, recovery, summaries)
    lowerer.emit_function_header(out / "lifted_functions.h")
    c_sources = lowerer.emit_functions(out)
    semantics_source = lowerer.emit_semantics(out)
    if semantics_source is not None:
        c_sources.append(semantics_source)
    c_sources.append(lowerer.emit_imports(out))
    c_sources.append(lowerer.emit_dispatch(out))
    payload, missing_data, relocation_count = emit_source_header(pe, recovery, out / "source.h")
    runtime_root = Path(__file__).resolve().parent / "runtime"
    for name in ("runtime.h", "runtime.cpp", "lifted_abi.h", "main.cpp", "diagnostics.h", "diagnostics.cpp"):
        shutil.copy2(runtime_root / name, out / name)
    project_name = symbol(pe.path.stem + "_native_c")
    dll_names = [path.name for path in sorted(root.iterdir()) if path.is_file() and path.suffix.lower() == ".dll"]
    emit_vcxproj(project_name, pe.path.stem, dll_names, c_sources, out / f"{project_name}.vcxproj")
    emit_solution(project_name, out / f"{project_name}.sln")
    emit_build_script(project_name, out / "build_release.cmd")
    emit_readme(out / "README.md")
    forbidden_hits = validate_native_output(out)
    entry_guard_hits = validate_function_entry_guards(pe, recovery, out)
    c_syntax_compiler, c_syntax_passed = portable_c_syntax_check(out, c_sources)
    runtime_syntax_compiler, runtime_syntax_passed = portable_runtime_syntax_check(out)
    direct_internal = sum(instruction.mnemonic == "call" and instruction.branch_target_rva in lowerer.function_seeds for instruction in recovery.instructions)
    direct_import = sum(instruction.mnemonic == "call" and instruction.operands and lowerer._direct_import(instruction.operands[0]) is not None for instruction in recovery.instructions)
    indirect_calls = sum(instruction.mnemonic == "call" for instruction in recovery.instructions) - direct_internal - direct_import
    config_function = next((function for function in recovery.functions if function.seed == lowerer.config_lookup_rva), None)
    normalized_instruction_count = (len(config_function.instructions) if config_function else 0) + (1 if lowerer.unsigned_decimal_callsite_rva is not None else 0)
    executable_ranges = [(section.raw_offset, section.raw_offset + section.raw_size) for section in pe.sections if section.executable and section.raw_size]
    executable_payload_is_zero = all(not any(payload[begin:end]) for begin, end in executable_ranges)
    report = {
        "input": pe.path.name,
        "input_sha256": pe.sha256,
        "code_free_payload_sha256": hashlib.sha256(payload).hexdigest(),
        "execution_model": "native-c-functions",
        "analysis_only_decoder_objects": True,
        "runtime_instruction_descriptors": False,
        "runtime_opcode_dispatch": False,
        "runtime_interpreter_loop": False,
        "native_c_normalizations": {
            "config_lookup": {
                "target": f"0x{summaries.config_lookup_target:08X}",
                "text_pointer_address": f"0x{summaries.config_text_pointer_address:08X}",
                "text_length_address": f"0x{summaries.config_text_length_address:08X}",
                "capacity": summaries.config_text_capacity,
                "implementation": "generated-c-function",
            },
            "unsigned_decimal_sso": {
                "target": f"0x{summaries.unsigned_decimal_target:08X}",
                "callsite": f"0x{summaries.unsigned_decimal_callsite:08X}",
                "implementation": "generated-c-callsite",
            },
        },
        "normalized_source_instructions": normalized_instruction_count,
        "function_entry_redirects": sum(function.instructions[0].rva != function.seed for function in recovery.functions),
        "function_entry_guards_passed": not entry_guard_hits,
        "function_entry_guard_failures": entry_guard_hits,
        "functions": len(recovery.functions),
        "reachable_instructions_lowered": len(recovery.instructions),
        "generated_instruction_statements": sum(len(function.instructions) for function in recovery.functions),
        "shared_tail_statement_clones": sum(len(function.instructions) for function in recovery.functions) - len(recovery.instructions),
        "basic_blocks": sum(len(function.leaders) for function in recovery.functions),
        "lowered_opcodes": dict(sorted(Counter(item.mnemonic for item in recovery.instructions).items())),
        "direct_internal_calls": direct_internal,
        "symbolic_iat_calls": direct_import,
        "indirect_calls": indirect_calls,
        "imports": len(pe.imports),
        "callback_bridges": len(recovery.callbacks),
        "jump_table_entries": len(recovery.jump_entries),
        "recovered_lookup_data_ranges": len(recovery.lookup_data),
        "recovered_lookup_data_bytes": sum(len(data) for _, data in recovery.lookup_data),
        "mapped_relocations": relocation_count,
        "uncovered_executable_data_references": [{"instruction": f"0x{pe.image_base + instruction:08X}", "data": f"0x{pe.image_base + data:08X}", "size": size} for instruction, data, size in missing_data],
        "original_executable_payload_is_zero": executable_payload_is_zero,
        "forbidden_runtime_hits": forbidden_hits,
        "generated_c_files": len(c_sources),
        "portable_c_syntax_compiler": c_syntax_compiler,
        "portable_c_syntax_tested": c_syntax_passed is not None,
        "portable_c_syntax_passed": c_syntax_passed,
        "portable_runtime_syntax_compiler": runtime_syntax_compiler,
        "portable_runtime_syntax_tested": runtime_syntax_passed is not None,
        "portable_runtime_syntax_passed": runtime_syntax_passed,
        "windows_release_build_tested": False,
        "elapsed_seconds": round(time.perf_counter() - started, 3),
    }
    report["static_checks_passed"] = executable_payload_is_zero and not missing_data and not forbidden_hits and not entry_guard_hits
    (out / "report.json").write_text(json.dumps(report, indent=2), encoding="utf-8", newline="\n")
    if not report["static_checks_passed"]:
        raise PEFormatError("Generated native C project failed static validation; inspect report.json")
    print(f"[done] C files={len(c_sources):,}, imports={direct_import:,}, indirect={indirect_calls:,}, callbacks={len(recovery.callbacks):,}, elapsed={report['elapsed_seconds']:.3f}s")
