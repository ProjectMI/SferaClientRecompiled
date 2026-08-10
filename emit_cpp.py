from __future__ import annotations

import bisect
import hashlib
import json
import re
import shutil
import struct
import time
from collections import Counter
from dataclasses import dataclass
from pathlib import Path

from pe32 import PE32, PEFormatError
from x86_ir import Instruction, Operand, X86Program, decode_program, decode_reachable


_CPP_KEYWORDS = {
    "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch", "char", "char16_t", "char32_t", "class", "compl", "concept", "const", "consteval", "constexpr", "constinit", "const_cast", "continue", "co_await", "co_return", "co_yield", "decltype", "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "std", "struct", "switch", "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
}
_BASE_OPCODES = {
    "adc", "add", "and", "call", "cdq", "clc", "cld", "cmc", "cmova", "cmovae", "cmovb", "cmovbe", "cmove", "cmovg", "cmovge", "cmovl", "cmovle", "cmovne", "cmovno", "cmovnp", "cmovns", "cmovo", "cmovp", "cmovs", "cmp", "cmpsb", "cmpsd", "cmpsw", "cvttsd2si", "cwde", "dec", "div", "fabs", "fadd", "faddp", "fchs", "fcom", "fcomp", "fcompp", "fdiv", "fdivp", "fdivr", "fdivrp", "fiadd", "fidiv", "fidivr", "fild", "fimul", "fist", "fistp", "fisttp", "fisub", "fisubr", "fld", "fld1", "fldcw", "fldz", "fmul", "fmulp", "fnstcw", "fnstsw", "fsincos", "fst", "fstp", "fsub", "fsubp", "fsubr", "fsubrp", "fucomp", "fucompp", "fxch", "idiv", "imul", "inc", "int3", "invalid", "ja", "jae", "jb", "jbe", "jcxz", "je", "jecxz", "jg", "jge", "jl", "jle", "jmp", "jne", "jno", "jnp", "jns", "jo", "jp", "js", "lahf", "lea", "leave", "lodsb", "lodsd", "lodsw", "loop", "loope", "loopne", "mov", "movsb", "movsd", "movsw", "movsx", "movups", "movzx", "mul", "neg", "nop", "not", "or", "pop", "popad", "popfd", "push", "pushad", "pushfd", "rcl", "rcr", "ret", "rol", "ror", "sahf", "sal", "sar", "sbb", "scasb", "scasd", "scasw", "seta", "setae", "setb", "setbe", "sete", "setg", "setge", "setl", "setle", "setne", "setno", "setnp", "setns", "seto", "setp", "sets", "shl", "shld", "shr", "shrd", "stc", "std", "stosb", "stosd", "stosw", "sub", "test", "wait", "xchg", "xor"
}
_REGISTERS = ["none", "al", "cl", "dl", "bl", "ah", "ch", "dh", "bh", "ax", "cx", "dx", "bx", "sp", "bp", "si", "di", "eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi", "cs", "ds", "es", "fs", "gs", "ss", "st0", "st1", "st2", "st3", "st4", "st5", "st6", "st7", "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7"]
_PROCESS_MODULE_ARGUMENTS = {("dinput8.dll", "DirectInput8Create"): 0}


def cpp_string(value: str) -> str:
    result = ['"']
    for byte in value.encode("utf-8"):
        if byte == 0x22:
            result.append('\\"')
        elif byte == 0x5C:
            result.append('\\\\')
        elif 0x20 <= byte <= 0x7E:
            result.append(chr(byte))
        else:
            result.append(f"\\x{byte:02X}")
    result.append('"')
    return "".join(result)


def identifier(value: str) -> str:
    value = re.sub(r"[^A-Za-z0-9_]", "_", value)
    return f"generated_{value}" if not value or value[0].isdigit() else value


def enum_token(value: str) -> str:
    token = re.sub(r"[^A-Za-z0-9_]", "_", value).strip("_").lower() or "unknown"
    if token[0].isdigit():
        token = f"op_{token}"
    return f"{token}_" if token in _CPP_KEYWORDS else token


def register_token(value: str | None) -> str:
    return enum_token(value or "none")


def process_module_argument(dll: str, name: str | None) -> int:
    return _PROCESS_MODULE_ARGUMENTS.get((dll.lower(), name or ""), -1)


def u32(value: int) -> str:
    return f"0x{value & 0xFFFFFFFF:08X}u"


@dataclass(frozen=True)
class SemanticSummaries:
    config_lookup_target: int = 0
    config_text_pointer_address: int = 0
    config_text_length_address: int = 0
    config_text_capacity: int = 0
    unsigned_decimal_target: int = 0
    unsigned_decimal_callsite: int = 0


def _is_register(operand: Operand, name: str) -> bool:
    return operand.kind == "register" and operand.reg == name


def _is_immediate(operand: Operand, value: int) -> bool:
    return operand.kind == "immediate" and operand.imm == value


def _is_memory(operand: Operand, base: str | None = None, displacement: int | None = None) -> bool:
    return operand.kind == "memory" and operand.base == base and operand.index is None and (displacement is None or operand.displacement == displacement)


def _literal_vas(pe: PE32, literal: bytes) -> set[int]:
    matches = set()
    for section in pe.sections:
        raw = pe.data[section.raw_offset:section.raw_offset + section.raw_size]
        offset = raw.find(literal)
        while offset >= 0:
            matches.add(pe.image_base + section.virtual_address + offset)
            offset = raw.find(literal, offset + 1)
    return matches


def _config_storage_contract(instructions: tuple[Instruction, ...], index: int, pointer_address: int) -> tuple[int, int]:
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


def _discover_config_summary(pe: PE32, instructions: tuple[Instruction, ...]) -> tuple[int, int, int, int]:
    candidates = set()
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
        raise PEFormatError("Config lookup summary is ambiguous; refusing to bind it to a guessed address")
    return next(iter(candidates), (0, 0, 0, 0))


def _discover_unsigned_decimal_summary(pe: PE32, instructions: tuple[Instruction, ...]) -> tuple[int, int]:
    literal_vas = _literal_vas(pe, b"NEW_FONT_\0")
    if not literal_vas:
        return 0, 0
    instruction_rvas = {item.rva for item in instructions}
    candidates = set()
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
        raise PEFormatError("NEW_FONT_ decimal summary was not identified unambiguously; refusing to generate a runtime that can corrupt font keys")
    return next(iter(candidates))


def discover_semantic_summaries(pe: PE32, instructions: tuple[Instruction, ...]) -> SemanticSummaries:
    config_target, config_pointer, config_length, config_capacity = _discover_config_summary(pe, instructions)
    decimal_target, decimal_callsite = _discover_unsigned_decimal_summary(pe, instructions)
    return SemanticSummaries(config_target, config_pointer, config_length, config_capacity, decimal_target, decimal_callsite)


def operand_cpp(operand: Operand) -> str:
    if operand.kind == "register":
        return f"R(Reg::{register_token(operand.reg)}, {operand.width}u)"
    if operand.kind == "immediate":
        return f"U({u32(operand.imm or 0)}, {operand.width}u, {'true' if operand.image_address else 'false'})"
    if operand.kind == "branch":
        return f"B({u32(operand.imm or 0)}, {'true' if operand.image_address else 'false'})"
    if operand.kind == "memory":
        return f"M({operand.width}u, Reg::{register_token(operand.base)}, Reg::{register_token(operand.index)}, {operand.scale}u, {u32(operand.displacement)}, Reg::{register_token(operand.segment)}, {'true' if operand.image_address else 'false'})"
    if operand.kind == "far_branch":
        return f"F({u32(operand.imm or 0)})"
    return "N()"


def instruction_flags(instruction: object) -> int:
    return (1 if instruction.rep else 0) | (2 if instruction.repe else 0) | (4 if instruction.repne else 0) | (8 if instruction.invalid else 0)


def validate_image_addresses(pe: PE32, instructions: tuple[Instruction, ...]) -> None:
    for instruction in instructions:
        for operand in instruction.operands:
            if not operand.image_address:
                continue
            value = operand.displacement if operand.kind == "memory" else operand.imm
            if value is None or not pe.image_base <= value < pe.image_base + pe.size_of_image:
                raise PEFormatError(f"IR image address is outside the source image at RVA 0x{instruction.rva:08X}")


def emit_ir_files(program: X86Program, out: Path, chunk_size: int = 8192) -> list[str]:
    max_operands = max((len(item.operands) for item in program.instructions), default=0)
    if max_operands > 3:
        raise PEFormatError(f"IR instruction has {max_operands} operands, while the runtime descriptor supports 3")
    opcodes = sorted(_BASE_OPCODES | {item.mnemonic for item in program.instructions})
    opcode_rows = [f"    {enum_token(name)}," for name in opcodes]
    opcode_names = [f"    {cpp_string(name)}," for name in opcodes]
    register_rows = [f"    {register_token(name)}," for name in _REGISTERS]
    chunks = [program.instructions[start:start + chunk_size] for start in range(0, len(program.instructions), chunk_size)]
    declarations: list[str] = []
    chunk_rows: list[str] = []
    source_names: list[str] = []
    for index, chunk in enumerate(chunks):
        symbol = f"kInstructions_{index:03d}"
        declarations.append(f"extern const InstructionDescriptor {symbol}[{len(chunk)}];")
        chunk_rows.append(f"    {{{symbol}, {len(chunk)}u}},")
        rows = []
        for instruction in chunk:
            operands = [operand_cpp(item) for item in instruction.operands]
            while len(operands) < 3:
                operands.append("N()")
            rows.append(f"    I(0x{instruction.rva:08X}u, {instruction.size}u, Op::{enum_token(instruction.mnemonic)}, {instruction_flags(instruction)}u, {len(instruction.operands)}u, {operands[0]}, {operands[1]}, {operands[2]}),")
        name = f"ir_{index:03d}.cpp"
        (out / name).write_text("\n".join(["#include \"ir_data.h\"", "", "namespace lifted {", "", f"const InstructionDescriptor {symbol}[{len(chunk)}] = {{", *rows, "};", "", "} // namespace lifted", ""]), encoding="utf-8", newline="\n")
        source_names.append(name)
    header = ["#pragma once", "", "#include <array>", "#include <cstddef>", "#include <cstdint>", "#include <string_view>", "", "namespace lifted {", "", "enum class Reg : std::uint8_t {", *register_rows, "};", "", "enum class OperandKind : std::uint8_t { none, reg, imm, mem, branch, far_branch };", "", "enum class Op : std::uint16_t {", *opcode_rows, "};", "", f"inline constexpr std::array<std::string_view, {len(opcodes)}> kOpNames = {{{{", *opcode_names, "}};", "inline constexpr std::string_view op_name(Op op) noexcept { return kOpNames[static_cast<std::size_t>(op)]; }", "", "inline constexpr std::uint8_t kPrefixRep = 1u;", "inline constexpr std::uint8_t kPrefixRepe = 2u;", "inline constexpr std::uint8_t kPrefixRepne = 4u;", "inline constexpr std::uint8_t kInvalidEncoding = 8u;", "", "struct OperandDescriptor { OperandKind kind; std::uint16_t width; Reg reg; Reg base; Reg index; Reg segment; std::uint8_t scale; bool image_address; std::uint32_t value; };", "struct InstructionDescriptor { std::uint32_t rva; std::uint8_t size; Op op; std::uint8_t prefixes; std::uint8_t operand_count; std::array<OperandDescriptor, 3> operands; };", "inline constexpr OperandDescriptor N() noexcept { return {OperandKind::none, 0u, Reg::none, Reg::none, Reg::none, Reg::none, 1u, false, 0u}; }", "inline constexpr OperandDescriptor R(Reg reg, std::uint16_t width) noexcept { return {OperandKind::reg, width, reg, Reg::none, Reg::none, Reg::none, 1u, false, 0u}; }", "inline constexpr OperandDescriptor U(std::uint32_t value, std::uint16_t width, bool image_address) noexcept { return {OperandKind::imm, width, Reg::none, Reg::none, Reg::none, Reg::none, 1u, image_address, value}; }", "inline constexpr OperandDescriptor B(std::uint32_t value, bool image_address) noexcept { return {OperandKind::branch, 32u, Reg::none, Reg::none, Reg::none, Reg::none, 1u, image_address, value}; }", "inline constexpr OperandDescriptor F(std::uint32_t value) noexcept { return {OperandKind::far_branch, 48u, Reg::none, Reg::none, Reg::none, Reg::none, 1u, false, value}; }", "inline constexpr OperandDescriptor M(std::uint16_t width, Reg base, Reg index, std::uint8_t scale, std::uint32_t displacement, Reg segment, bool image_address) noexcept { return {OperandKind::mem, width, Reg::none, base, index, segment, scale, image_address, displacement}; }", "inline constexpr InstructionDescriptor I(std::uint32_t rva, std::uint8_t size, Op op, std::uint8_t prefixes, std::uint8_t operand_count, OperandDescriptor a, OperandDescriptor b, OperandDescriptor c) noexcept { return {rva, size, op, prefixes, operand_count, {a, b, c}}; }", "", "struct InstructionChunk { const InstructionDescriptor* data; std::size_t size; };", *declarations, "", f"inline const std::array<InstructionChunk, {len(chunks)}> kInstructionChunks = {{{{", *chunk_rows, "}};", "", "} // namespace lifted", ""]
    (out / "ir_data.h").write_text("\n".join(header), encoding="utf-8", newline="\n")
    return source_names


def hex_chunks(data: bytes, bytes_per_chunk: int = 4096) -> list[str]:
    return [data[start:start + bytes_per_chunk].hex().upper() for start in range(0, len(data), bytes_per_chunk)]


def section_for_rva(pe: PE32, rva: int) -> str:
    for section in pe.sections:
        if section.virtual_address <= rva < section.virtual_address + section.mapped_size:
            return section.name
    return "headers"


def _bounded_index_count(by_end: dict[int, Instruction], instruction: Instruction, register: str) -> int | None:
    cursor = instruction.rva
    for _ in range(8):
        branch = by_end.get(cursor)
        if branch is None:
            return None
        if branch.mnemonic in {"ja", "jae"}:
            compare = by_end.get(branch.rva)
            if compare is None or branch.branch_target_rva is None or branch.branch_target_rva <= instruction.rva or len(compare.operands) != 2:
                return None
            left, right = compare.operands
            if compare.mnemonic != "cmp" or left.kind != "register" or left.reg != register or right.kind != "immediate":
                return None
            count = (right.imm or 0) + (1 if branch.mnemonic == "ja" else 0)
            return count if 0 < count <= 1_000_000 else None
        cursor = branch.rva
    return None


def recovered_lookup_data(pe: PE32, instructions: tuple[Instruction, ...]) -> list[tuple[int, bytes]]:
    by_end = {instruction.next_rva: instruction for instruction in instructions}
    recovered: set[int] = set()
    for instruction in instructions:
        if instruction.mnemonic in {"jmp", "lea"}:
            continue
        for operand in instruction.operands:
            registers = [register for register in (operand.base, operand.index) if register]
            if operand.kind != "memory" or operand.width <= 0 or len(registers) != 1:
                continue
            address = (operand.displacement or 0) & 0xFFFFFFFF
            rva = address - pe.image_base
            section = next((item for item in pe.sections if item.executable and item.virtual_address <= rva < item.virtual_address + item.raw_size), None)
            if section is None:
                continue
            count = _bounded_index_count(by_end, instruction, registers[0])
            if count is None:
                continue
            stride = operand.scale if operand.index else 1
            size = (count - 1) * stride + (operand.width + 7) // 8
            if rva + size > section.virtual_address + section.raw_size:
                raise PEFormatError(f"Recovered lookup data exceeds section {section.name} at VA 0x{address:08X}")
            recovered.update(range(rva, rva + size))
    image = pe.mapped_image()
    ranges: list[tuple[int, bytes]] = []
    for rva in sorted(recovered):
        if ranges and ranges[-1][0] + len(ranges[-1][1]) == rva:
            begin, data = ranges[-1]
            ranges[-1] = begin, data + bytes([image[rva]])
        else:
            ranges.append((rva, bytes([image[rva]])))
    return ranges


def uncovered_executable_data_references(pe: PE32, instructions: tuple[Instruction, ...], jump_entries: list[tuple[int, int]], recovered_data: list[tuple[int, bytes]]) -> list[tuple[int, int, int]]:
    executable = [(section.virtual_address, section.virtual_address + section.raw_size) for section in pe.sections if section.executable and section.raw_size]
    covered = {byte for rva, _ in jump_entries for byte in range(rva, rva + 4)} | {byte for rva, data in recovered_data for byte in range(rva, rva + len(data))}
    missing: set[tuple[int, int, int]] = set()
    for instruction in instructions:
        if instruction.rva in covered:
            continue
        for operand in instruction.operands:
            if operand.kind != "memory" or operand.width <= 0:
                continue
            address = (operand.displacement or 0) & 0xFFFFFFFF
            rva = address - pe.image_base
            size = (operand.width + 7) // 8
            if any(begin <= rva < end for begin, end in executable) and any(rva + offset not in covered for offset in range(size)):
                missing.add((instruction.rva, rva, size))
    return sorted(missing)


def callback_targets(pe: PE32, jump_entries: list[tuple[int, int]] | None = None, recovered_data: list[tuple[int, bytes]] | None = None) -> list[int]:
    image = pe.mapped_image()
    executable = [(pe.image_base + section.virtual_address, pe.image_base + section.virtual_address + section.mapped_size) for section in pe.sections if section.executable]
    jump_sources = {rva for rva, _ in jump_entries or []}
    jump_bytes = {byte for rva, _ in jump_entries or [] for byte in range(rva, rva + 4)}
    data_bytes = {byte for rva, data in recovered_data or [] for byte in range(rva, rva + len(data))}
    candidates: dict[int, int] = {}
    for relocation in pe.relocations:
        if relocation.kind != 3 or relocation.rva + 4 > len(image):
            continue
        if relocation.rva in jump_sources:
            continue
        value = struct.unpack_from("<I", image, relocation.rva)[0]
        if not any(begin <= value < end for begin, end in executable):
            continue
        target_rva = value - pe.image_base
        if any(target_rva + offset in jump_bytes for offset in range(5)):
            continue
        if any(target_rva + offset in data_bytes for offset in range(5)):
            continue
        priority = 0 if not any(section.executable and section.virtual_address <= relocation.rva < section.virtual_address + section.mapped_size for section in pe.sections) else 1
        candidates[value] = min(candidates.get(value, priority), priority)
    selected: list[int] = []
    rejected: list[int] = []
    for value, _ in sorted(candidates.items(), key=lambda item: (item[1], item[0])):
        position = bisect.bisect_left(selected, value)
        before_ok = position == 0 or value - selected[position - 1] >= 5
        after_ok = position == len(selected) or selected[position] - value >= 5
        if before_ok and after_ok:
            selected.insert(position, value)
        else:
            rejected.append(value)
    if rejected:
        raise PEFormatError(f"Callback targets require overlapping five-byte stubs near VA 0x{rejected[0]:08X}")
    return [value - pe.image_base for value in selected]


def jump_table_entries(pe: PE32, program: X86Program) -> list[tuple[int, int]]:
    image = pe.mapped_image()
    executable = [(pe.image_base + section.virtual_address, pe.image_base + section.virtual_address + section.mapped_size) for section in pe.sections if section.executable]
    relocation_rvas = {relocation.rva for relocation in pe.relocations if relocation.kind == 3}
    table_bases: set[int] = set()
    for instruction in program.instructions:
        if instruction.mnemonic != "jmp":
            continue
        for operand in instruction.operands:
            address = (operand.displacement or 0) & 0xFFFFFFFF
            indexed = operand.kind == "memory" and operand.base is None and operand.index is not None and operand.scale == 4 and operand.width == 32
            if indexed and any(begin <= address < end for begin, end in executable):
                table_bases.add(address)
    entries: dict[int, int] = {}
    for base in sorted(table_bases):
        cursor = base - pe.image_base
        found = 0
        while cursor in relocation_rvas and cursor + 4 <= len(image):
            target = struct.unpack_from("<I", image, cursor)[0]
            if not any(begin <= target < end for begin, end in executable):
                break
            entries[cursor] = target
            cursor += 4
            found += 1
        if found == 0:
            raise PEFormatError(f"Unable to recover switch table at VA 0x{base:08X}")
    instruction_rvas = {instruction.rva for instruction in program.instructions}
    invalid_targets = [(rva, target) for rva, target in entries.items() if target - pe.image_base not in instruction_rvas]
    if invalid_targets:
        rva, target = invalid_targets[0]
        raise PEFormatError(f"Switch entry RVA 0x{rva:08X} targets undecoded VA 0x{target:08X}")
    return sorted(entries.items())


def code_free_payload(pe: PE32) -> bytes:
    payload = bytearray(pe.data)
    for section in pe.sections:
        if section.executable and section.raw_size:
            payload[section.raw_offset:section.raw_offset + section.raw_size] = bytes(section.raw_size)
    return bytes(payload)


def emit_source_header(pe: PE32, program: X86Program, data_analysis_instructions: tuple[Instruction, ...], summaries: SemanticSummaries, output: Path) -> tuple[int, int, int, int, int, list[tuple[int, int, int]], bytes]:
    section_rows = []
    for section in pe.sections:
        access = (1 if section.readable else 0) | (2 if section.writable else 0) | (4 if section.executable else 0)
        section_rows.append(f"    {{{cpp_string(section.name)}, 0x{section.virtual_address:08X}u, 0x{section.virtual_size:08X}u, 0x{section.raw_offset:08X}u, 0x{section.raw_size:08X}u, {access}u}},")
    import_rows = [f"    {{{cpp_string(symbol.dll)}, {cpp_string(symbol.name or '')}, 0x{symbol.iat_rva:08X}u, {symbol.ordinal or 0}u, {'true' if symbol.ordinal is not None else 'false'}, {process_module_argument(symbol.dll, symbol.name)}}}," for symbol in pe.imports]
    jump_entries = jump_table_entries(pe, program)
    jump_rows = [f"    {{0x{rva:08X}u, 0x{target:08X}u}}," for rva, target in jump_entries]
    recovered_data = recovered_lookup_data(pe, data_analysis_instructions)
    missing_executable_data = uncovered_executable_data_references(pe, data_analysis_instructions, jump_entries, recovered_data)
    recovered_rows = [f"    {{0x{rva:08X}u, {cpp_string(data.hex().upper())}}}," for rva, data in recovered_data]
    callbacks = callback_targets(pe, jump_entries, recovered_data)
    callback_rows = [f"    {{0x{rva:08X}u}}," for rva in callbacks]
    instruction_rvas = {instruction.rva for instruction in program.instructions}
    if any(rva not in instruction_rvas for rva in callbacks):
        raise PEFormatError("Generated callback targets include an undecoded image address")
    callback_bytes = {byte for rva in callbacks for byte in range(rva, rva + 5)}
    jump_bytes = {byte for rva, _ in jump_entries for byte in range(rva, rva + 4)}
    recovered_bytes = {byte for rva, data in recovered_data for byte in range(rva, rva + len(data))}
    if callback_bytes & jump_bytes:
        raise PEFormatError("Generated callback stubs overlap recovered switch data")
    if callback_bytes & recovered_bytes:
        raise PEFormatError("Generated callback stubs overlap recovered lookup data")
    if jump_bytes & recovered_bytes:
        raise PEFormatError("Recovered switch and lookup data overlap")
    executable_ranges = [(section.virtual_address, section.virtual_address + section.mapped_size) for section in pe.sections if section.executable]
    restored_executable_bytes = jump_bytes | recovered_bytes
    relocation_rvas = []
    for relocation in pe.relocations:
        if relocation.kind != 3 or relocation.rva + 4 > pe.size_of_image:
            continue
        in_executable = any(begin <= relocation.rva < end for begin, end in executable_ranges)
        if not in_executable or all(relocation.rva + offset in restored_executable_bytes for offset in range(4)):
            relocation_rvas.append(relocation.rva)
    mapped_image = pe.mapped_image()
    for rva in relocation_rvas:
        source_va = struct.unpack_from("<I", mapped_image, rva)[0]
        if not pe.image_base <= source_va < pe.image_base + pe.size_of_image:
            raise PEFormatError(f"Local relocation at RVA 0x{rva:08X} does not contain an image address")
    relocation_rows = [f"    {{0x{rva:08X}u}}," for rva in relocation_rvas]
    payload = code_free_payload(pe)
    chunks = hex_chunks(payload)
    chunk_definitions = [f"inline constexpr char kMappedPayloadHex_{index}[] = {cpp_string(chunk)};" for index, chunk in enumerate(chunks)]
    chunk_rows = [f"    {{kMappedPayloadHex_{index}, sizeof(kMappedPayloadHex_{index}) - 1}}," for index in range(len(chunks))]
    rvas = [item.rva for item in program.instructions]
    content = f'''#pragma once

#include "ir_data.h"

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
inline constexpr std::uint32_t kCodeMinRva = 0x{min(rvas):08X}u;
inline constexpr std::uint32_t kCodeMaxRva = 0x{max(rvas) + 1:08X}u;
inline constexpr std::uint16_t kMachine = 0x{pe.machine:04X}u;
inline constexpr std::size_t kMappedPayloadSize = {len(pe.data)}u;
inline constexpr std::size_t kInstructionCount = {len(program.instructions)}u;
inline constexpr std::string_view kClientExecutableName = {cpp_string(pe.path.name)};
inline constexpr std::uint32_t kConfigLookupTarget = {u32(summaries.config_lookup_target)};
inline constexpr std::uint32_t kConfigTextPointerAddress = {u32(summaries.config_text_pointer_address)};
inline constexpr std::uint32_t kConfigTextLengthAddress = {u32(summaries.config_text_length_address)};
inline constexpr std::uint32_t kConfigTextCapacity = {u32(summaries.config_text_capacity)};
inline constexpr std::uint32_t kUnsignedDecimalStringTarget = {u32(summaries.unsigned_decimal_target)};
inline constexpr std::uint32_t kUnsignedDecimalStringCallsite = {u32(summaries.unsigned_decimal_callsite)};

struct SectionDescriptor {{ std::string_view name; std::uint32_t virtual_address; std::uint32_t virtual_size; std::uint32_t raw_offset; std::uint32_t raw_size; std::uint8_t access; }};
struct ImportDescriptor {{ std::string_view dll; std::string_view name; std::uint32_t iat_rva; std::uint16_t ordinal; bool by_ordinal; std::int8_t process_module_argument; }};
struct CallbackDescriptor {{ std::uint32_t rva; }};
struct JumpTableDescriptor {{ std::uint32_t rva; std::uint32_t target; }};
struct RecoveredDataDescriptor {{ std::uint32_t rva; std::string_view hex; }};
struct RelocationDescriptor {{ std::uint32_t rva; }};
struct HexChunk {{ const char* data; std::size_t size; }};

inline constexpr std::array<SectionDescriptor, {len(pe.sections)}> kSections = {{{{
{chr(10).join(section_rows)}
}}}};
inline constexpr std::array<ImportDescriptor, {len(pe.imports)}> kImports = {{{{
{chr(10).join(import_rows)}
}}}};
inline constexpr std::array<CallbackDescriptor, {len(callbacks)}> kCallbacks = {{{{
{chr(10).join(callback_rows)}
}}}};
inline constexpr std::array<JumpTableDescriptor, {len(jump_entries)}> kJumpTableEntries = {{{{
{chr(10).join(jump_rows)}
}}}};
inline constexpr std::array<RecoveredDataDescriptor, {len(recovered_data)}> kRecoveredData = {{{{
{chr(10).join(recovered_rows)}
}}}};
inline constexpr std::array<RelocationDescriptor, {len(relocation_rvas)}> kLocalRelocations = {{{{
{chr(10).join(relocation_rows)}
}}}};

{chr(10).join(chunk_definitions)}
inline constexpr std::array<HexChunk, {len(chunks)}> kMappedPayloadHex = {{{{
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
    return len(callbacks), len(jump_entries), len(recovered_data), len(recovered_bytes), len(relocation_rvas), missing_executable_data, payload


def emit_vcxproj(project_name: str, target_name: str, dll_names: list[str], ir_sources: list[str], output: Path) -> None:
    copies = "&#xD;&#xA;".join(f'copy /Y "$(ProjectDir)..\\{name}" "$(OutDir){name}" &gt;nul' for name in dll_names)
    ir_compile_rows = "".join(f'<ClCompile Include="{name}" />' for name in ir_sources)
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
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'"><ClCompile><WarningLevel>Level4</WarningLevel><Optimization>MaxSpeed</Optimization><InlineFunctionExpansion>AnySuitable</InlineFunctionExpansion><IntrinsicFunctions>true</IntrinsicFunctions><FunctionLevelLinking>true</FunctionLevelLinking><FavorSizeOrSpeed>Speed</FavorSizeOrSpeed><DebugInformationFormat>ProgramDatabase</DebugInformationFormat><BasicRuntimeChecks>Default</BasicRuntimeChecks><SDLCheck>true</SDLCheck><PreprocessorDefinitions>WIN32;_DEBUG;_ITERATOR_DEBUG_LEVEL=0;UNICODE;_UNICODE;%(PreprocessorDefinitions)</PreprocessorDefinitions><ConformanceMode>true</ConformanceMode><LanguageStandard>stdcpp20</LanguageStandard><RuntimeLibrary>MultiThreadedDebug</RuntimeLibrary><MultiProcessorCompilation>true</MultiProcessorCompilation></ClCompile><Link><SubSystem>Windows</SubSystem><GenerateDebugInformation>true</GenerateDebugInformation><RandomizedBaseAddress>true</RandomizedBaseAddress><DataExecutionPrevention>true</DataExecutionPrevention><TargetMachine>MachineX86</TargetMachine></Link><PostBuildEvent><Command>{copies}</Command></PostBuildEvent></ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'"><ClCompile><WarningLevel>Level4</WarningLevel><Optimization>MaxSpeed</Optimization><InlineFunctionExpansion>AnySuitable</InlineFunctionExpansion><FunctionLevelLinking>true</FunctionLevelLinking><IntrinsicFunctions>true</IntrinsicFunctions><FavorSizeOrSpeed>Speed</FavorSizeOrSpeed><SDLCheck>true</SDLCheck><PreprocessorDefinitions>WIN32;NDEBUG;UNICODE;_UNICODE;%(PreprocessorDefinitions)</PreprocessorDefinitions><ConformanceMode>true</ConformanceMode><LanguageStandard>stdcpp20</LanguageStandard><RuntimeLibrary>MultiThreaded</RuntimeLibrary><MultiProcessorCompilation>true</MultiProcessorCompilation></ClCompile><Link><SubSystem>Windows</SubSystem><EnableCOMDATFolding>true</EnableCOMDATFolding><OptimizeReferences>true</OptimizeReferences><GenerateDebugInformation>true</GenerateDebugInformation><RandomizedBaseAddress>true</RandomizedBaseAddress><DataExecutionPrevention>true</DataExecutionPrevention><TargetMachine>MachineX86</TargetMachine></Link><PostBuildEvent><Command>{copies}</Command></PostBuildEvent></ItemDefinitionGroup>
  <ItemGroup><ClCompile Include="diagnostics.cpp" /><ClCompile Include="main.cpp" /><ClCompile Include="runtime.cpp" />{ir_compile_rows}</ItemGroup>
  <ItemGroup><ClInclude Include="diagnostics.h" /><ClInclude Include="runtime.h" /><ClInclude Include="source.h" /><ClInclude Include="ir_data.h" /></ItemGroup>
  <Import Project="$(VCTargetsPath)\\Microsoft.Cpp.targets" />
</Project>
'''
    output.write_text(content, encoding="utf-8", newline="\n")


def emit_sln(project_name: str, output: Path) -> None:
    content = f'''Microsoft Visual Studio Solution File, Format Version 12.00
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
'''
    output.write_text(content, encoding="utf-8", newline="\n")


def emit_build_cmd(project_name: str, output: Path) -> None:
    output.write_text(f'''@echo off
setlocal
where msbuild >nul 2>nul
if errorlevel 1 (
    echo MSBuild was not found. Run this file from a Visual Studio Developer Command Prompt.
    exit /b 1
)
msbuild "{project_name}.sln" /t:Rebuild /m /p:Configuration=Release /p:Platform=x86
endlocal
''', encoding="utf-8", newline="\r\n")


def emit_readme(output: Path) -> None:
    output.write_text("""# Sfera: интерпретатор структурированного IR

Этот Win32/x86-проект исполняет декодированный IR и не восстанавливает исходные x86-инструкции из секции `.text`. PE-заголовки, ресурсы и секции данных загружаются в локальную память текущего процесса; в обнулённой исполняемой секции создаются только мосты callback-вызовов и восстановленные таблицы данных. Генерация завершается ошибкой, если ссылка на данные внутри исполняемой секции остаётся неклассифицированной.

Сборка: запустите `build_release.cmd` из Visual Studio 2022 Developer Command Prompt с установленным набором Desktop development with C++. Результат появится в `bin\\Release`; необходимые DLL копируются туда автоматически. Конфигурации Debug и Release используют оптимизацию скорости, при этом Debug сохраняет PDB и отладочную CRT.

Программа работает в одном процессе. Локальный образ размещается по свободному адресу, PE-релокации и адресные операнды IR переводятся к его фактической базе. Рантайм находит корень ресурсов по `mbc\\_main.mbc`, назначает его рабочим каталогом и виртуализирует `GetModuleFileNameA/W` путём исходного клиентского EXE. Если автообнаружение невозможно, задайте каталог клиента в `SFERA_CLIENT_ROOT`.

Рантайм сохраняет регистры и EFLAGS, использует локальный стек, моделирует x87 и FS/SEH-данные, поддерживает cdecl/stdcall/thiscall/fastcall и callback-вызовы через единый x86-мост. `SFERA_IR_DEEP_TRACE=1` включает защищённые пробы и происхождение записей. Контролируемая ошибка создаёт `sfera_ir_failure.txt`; нативное падение создаёт `sfera_ir_crash.txt` и `sfera_ir_crash.dmp`. Нативное C++/SEH-исключение, пересекающее границу интерпретатора, пока не поддерживается.

Статические результаты проверки генерации и вычисленные привязки semantic summaries находятся в `report.json`. Полная проверка поведения требует запуска Release/Win32-сборки на Windows.
""", encoding="utf-8", newline="\n")


def parse_local_modules(root: Path) -> dict[str, PE32]:
    modules = {}
    for path in sorted(root.iterdir()):
        if not path.is_file() or path.suffix.lower() != ".dll":
            continue
        try:
            modules[path.name.lower()] = PE32(path)
        except PEFormatError:
            continue
    return modules


def generate(pe: PE32, root: Path, out: Path) -> None:
    started = time.perf_counter()
    if out.exists():
        shutil.rmtree(out)
    out.mkdir(parents=True)
    local_modules = parse_local_modules(root)
    project_name = identifier(pe.path.stem + "_ir_runtime")
    print("[decode] structured x86 IR")
    program = decode_program(pe)
    entry_reachable = decode_reachable(pe)
    validate_image_addresses(pe, program.instructions)
    summaries = discover_semantic_summaries(pe, program.instructions)
    print(f"[semantic] config={summaries.config_lookup_target:#010x}, decimal={summaries.unsigned_decimal_target:#010x} at {summaries.unsigned_decimal_callsite:#010x}")
    print(f"[emit] {len(program.instructions):,} instructions")
    ir_sources = emit_ir_files(program, out)
    callback_count, jump_table_count, recovered_data_range_count, recovered_data_byte_count, mapped_relocation_count, missing_executable_data, payload = emit_source_header(pe, program, program.instructions, summaries, out / "source.h")
    runtime_root = Path(__file__).resolve().parent / "runtime"
    shutil.copy2(runtime_root / "runtime.h", out / "runtime.h")
    shutil.copy2(runtime_root / "runtime.cpp", out / "runtime.cpp")
    shutil.copy2(runtime_root / "main.cpp", out / "main.cpp")
    shutil.copy2(runtime_root / "diagnostics.h", out / "diagnostics.h")
    shutil.copy2(runtime_root / "diagnostics.cpp", out / "diagnostics.cpp")
    emit_vcxproj(project_name, pe.path.stem, [module.path.name for module in local_modules.values()], ir_sources, out / f"{project_name}.vcxproj")
    emit_sln(project_name, out / f"{project_name}.sln")
    emit_build_cmd(project_name, out / "build_release.cmd")
    emit_readme(out / "README.md")
    runtime_references = set(re.findall(r"Op::([A-Za-z_][A-Za-z0-9_]*)", (runtime_root / "runtime.cpp").read_text(encoding="utf-8")))
    entry_mnemonics = Counter(item.mnemonic for item in entry_reachable)
    unhandled_entry = sorted(name for name in entry_mnemonics if enum_token(name) not in runtime_references)
    instruction_rvas = {item.rva for item in program.instructions}
    missing_direct_targets = sorted({item.branch_target_rva for item in entry_reachable if item.branch_target_rva is not None and item.branch_target_rva not in instruction_rvas})
    executable_ranges = [(section.raw_offset, section.raw_offset + section.raw_size) for section in pe.sections if section.executable and section.raw_size]
    executable_payload_is_zero = all(not any(payload[begin:end]) for begin, end in executable_ranges)
    invalid_entry = sum(item.invalid for item in entry_reachable)
    static_checks_passed = executable_payload_is_zero and invalid_entry == 0 and not unhandled_entry and not missing_direct_targets and not missing_executable_data
    report = {
        "input": pe.path.name,
        "input_sha256": pe.sha256,
        "code_free_payload_sha256": hashlib.sha256(payload).hexdigest(),
        "runtime": "structured-ir-interpreter",
        "address_model": "single-process-relocated-local-image",
        "instructions": len(program.instructions),
        "entry_reachable_instructions": len(entry_reachable),
        "entry_reachable_opcodes": dict(sorted(entry_mnemonics.items())),
        "all_linear_opcodes": dict(sorted(Counter(item.mnemonic for item in program.instructions).items())),
        "imports": len(pe.imports),
        "process_module_alias_imports": sum(process_module_argument(symbol.dll, symbol.name) >= 0 for symbol in pe.imports),
        "local_image_relocations": sum(item.kind == 3 for item in pe.relocations),
        "mapped_local_relocations": mapped_relocation_count,
        "rebased_ir_operands": sum(operand.image_address for instruction in program.instructions for operand in instruction.operands),
        "semantic_summaries": {
            "config_lookup": {"target": f"0x{summaries.config_lookup_target:08X}", "text_pointer_address": f"0x{summaries.config_text_pointer_address:08X}", "text_length_address": f"0x{summaries.config_text_length_address:08X}", "capacity": summaries.config_text_capacity},
            "unsigned_decimal_string": {"target": f"0x{summaries.unsigned_decimal_target:08X}", "callsite": f"0x{summaries.unsigned_decimal_callsite:08X}"},
        },
        "callback_bridges": callback_count,
        "jump_table_entries": jump_table_count,
        "recovered_lookup_data_ranges": recovered_data_range_count,
        "recovered_lookup_data_bytes": recovered_data_byte_count,
        "uncovered_executable_data_references": [{"instruction": f"0x{instruction_rva + pe.image_base:08X}", "data": f"0x{data_rva + pe.image_base:08X}", "size": size} for instruction_rva, data_rva, size in missing_executable_data],
        "original_text_embedded": False,
        "original_x86_instructions_embedded": False,
        "executable_payload_is_zero": executable_payload_is_zero,
        "invalid_entry_instructions": invalid_entry,
        "unhandled_entry_opcodes": unhandled_entry,
        "missing_direct_targets": [f"0x{item:08X}" for item in missing_direct_targets],
        "static_checks_passed": static_checks_passed,
        "windows_runtime_tested": False,
        "elapsed_seconds": round(time.perf_counter() - started, 3),
    }
    (out / "report.json").write_text(json.dumps(report, indent=2), encoding="utf-8", newline="\n")
    if not static_checks_passed:
        raise PEFormatError("Generated runtime failed static validation; inspect report.json")
    print(f"[done] callbacks={callback_count:,}, jump-entries={jump_table_count:,}, lookup-data={recovered_data_range_count:,}/{recovered_data_byte_count:,}B, static-checks=passed, elapsed={report['elapsed_seconds']:.3f}s")
