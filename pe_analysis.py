from __future__ import annotations

import bisect
import struct

from pe32 import PE32, PEFormatError
from x86_decode import DecodedInstruction, DecodedProgram


def _bounded_index_count(by_end: dict[int, DecodedInstruction], instruction: DecodedInstruction, register: str) -> int | None:
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


def recover_lookup_data(pe: PE32, instructions: tuple[DecodedInstruction, ...]) -> list[tuple[int, bytes]]:
    by_end = {instruction.next_rva: instruction for instruction in instructions}
    recovered: set[int] = set()
    for instruction in instructions:
        if instruction.mnemonic in {"jmp", "lea"}:
            continue
        for operand in instruction.operands:
            registers = [register for register in (operand.base, operand.index) if register]
            if operand.kind != "memory" or operand.width <= 0 or len(registers) != 1:
                continue
            address = operand.displacement & 0xFFFFFFFF
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


def recover_jump_tables(pe: PE32, program: DecodedProgram) -> list[tuple[int, int]]:
    image = pe.mapped_image()
    executable = [(pe.image_base + section.virtual_address, pe.image_base + section.virtual_address + section.mapped_size) for section in pe.sections if section.executable]
    relocation_rvas = {relocation.rva for relocation in pe.relocations if relocation.kind == 3}
    table_bases: set[int] = set()
    for instruction in program.instructions:
        if instruction.mnemonic != "jmp" or not instruction.operands:
            continue
        operand = instruction.operands[0]
        address = operand.displacement & 0xFFFFFFFF
        indexed = operand.kind == "memory" and operand.base is None and operand.index is not None and operand.scale == 4 and operand.width == 32
        if indexed and any(begin <= address < end for begin, end in executable):
            table_bases.add(address)
    entries: dict[int, int] = {}
    for base in sorted(table_bases):
        cursor = base - pe.image_base
        count = 0
        while cursor in relocation_rvas and cursor + 4 <= len(image):
            target = struct.unpack_from("<I", image, cursor)[0]
            if not any(begin <= target < end for begin, end in executable):
                break
            entries[cursor] = target
            cursor += 4
            count += 1
        if count == 0:
            raise PEFormatError(f"Unable to recover switch table at VA 0x{base:08X}")
    instruction_rvas = {instruction.rva for instruction in program.instructions}
    invalid = [(rva, target) for rva, target in entries.items() if target - pe.image_base not in instruction_rvas]
    if invalid:
        rva, target = invalid[0]
        raise PEFormatError(f"Switch entry RVA 0x{rva:08X} targets undecoded VA 0x{target:08X}")
    return sorted(entries.items())


def recover_callback_targets(pe: PE32, jump_entries: list[tuple[int, int]], lookup_data: list[tuple[int, bytes]]) -> list[int]:
    image = pe.mapped_image()
    executable = [(pe.image_base + section.virtual_address, pe.image_base + section.virtual_address + section.mapped_size) for section in pe.sections if section.executable]
    jump_sources = {rva for rva, _ in jump_entries}
    jump_bytes = {byte for rva, _ in jump_entries for byte in range(rva, rva + 4)}
    data_bytes = {byte for rva, data in lookup_data for byte in range(rva, rva + len(data))}
    candidates: dict[int, int] = {}
    for relocation in pe.relocations:
        if relocation.kind != 3 or relocation.rva + 4 > len(image) or relocation.rva in jump_sources:
            continue
        value = struct.unpack_from("<I", image, relocation.rva)[0]
        if not any(begin <= value < end for begin, end in executable):
            continue
        target_rva = value - pe.image_base
        if any(target_rva + offset in jump_bytes or target_rva + offset in data_bytes for offset in range(5)):
            continue
        in_code = any(section.executable and section.virtual_address <= relocation.rva < section.virtual_address + section.mapped_size for section in pe.sections)
        priority = 1 if in_code else 0
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


def uncovered_executable_data(pe: PE32, instructions: tuple[DecodedInstruction, ...], jump_entries: list[tuple[int, int]], lookup_data: list[tuple[int, bytes]]) -> list[tuple[int, int, int]]:
    executable = [(section.virtual_address, section.virtual_address + section.raw_size) for section in pe.sections if section.executable and section.raw_size]
    covered = {byte for rva, _ in jump_entries for byte in range(rva, rva + 4)}
    covered.update(byte for rva, data in lookup_data for byte in range(rva, rva + len(data)))
    missing: set[tuple[int, int, int]] = set()
    for instruction in instructions:
        if instruction.rva in covered:
            continue
        for operand in instruction.operands:
            if operand.kind != "memory" or operand.width <= 0:
                continue
            rva = (operand.displacement & 0xFFFFFFFF) - pe.image_base
            size = (operand.width + 7) // 8
            if any(begin <= rva < end for begin, end in executable) and any(rva + offset not in covered for offset in range(size)):
                missing.add((instruction.rva, rva, size))
    return sorted(missing)


def code_free_payload(pe: PE32) -> bytes:
    payload = bytearray(pe.data)
    for section in pe.sections:
        if section.executable and section.raw_size:
            payload[section.raw_offset:section.raw_offset + section.raw_size] = bytes(section.raw_size)
    return bytes(payload)
