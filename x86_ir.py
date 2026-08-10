from __future__ import annotations

import struct
from collections import deque
from dataclasses import dataclass

from pe32 import PE32, Section

try:
    import iced_x86 as iced
except ImportError as error:
    raise RuntimeError("iced-x86 is required; install dependencies with: py -m pip install -r requirements.txt") from error


class X86DecodeError(RuntimeError):
    pass


@dataclass(frozen=True)
class Operand:
    kind: str
    width: int
    reg: str | None = None
    imm: int | None = None
    base: str | None = None
    index: str | None = None
    scale: int = 1
    displacement: int = 0
    segment: str | None = None
    image_address: bool = False


@dataclass(frozen=True)
class Instruction:
    rva: int
    size: int
    mnemonic: str
    code: str
    operands: tuple[Operand, ...]
    branch_target_rva: int | None
    flow: str
    rep: bool
    repe: bool
    repne: bool
    invalid: bool
    text: str

    @property
    def next_rva(self) -> int:
        return self.rva + self.size


@dataclass(frozen=True)
class DecodedSection:
    section: Section
    instructions: tuple[Instruction, ...]


@dataclass(frozen=True)
class X86Program:
    sections: tuple[DecodedSection, ...]

    @property
    def instructions(self) -> tuple[Instruction, ...]:
        return tuple(item for section in self.sections for item in section.instructions)


def _enum_names(enum_type: object) -> dict[int, str]:
    return {value: name.lower() for name, value in vars(enum_type).items() if name.isupper() and isinstance(value, int)}


_REGISTER_NAMES = _enum_names(iced.Register)
_MNEMONIC_NAMES = _enum_names(iced.Mnemonic)
_CODE_NAMES = _enum_names(iced.Code)
_OP_KIND_NAMES = _enum_names(iced.OpKind)
_FLOW_NAMES = _enum_names(iced.FlowControl)
_FORMATTER = iced.Formatter(iced.FormatterSyntax.NASM)
_IMMEDIATE_WIDTHS = {
    iced.OpKind.IMMEDIATE8: 8,
    iced.OpKind.IMMEDIATE8_2ND: 8,
    iced.OpKind.IMMEDIATE16: 16,
    iced.OpKind.IMMEDIATE32: 32,
    iced.OpKind.IMMEDIATE64: 64,
    iced.OpKind.IMMEDIATE8TO16: 16,
    iced.OpKind.IMMEDIATE8TO32: 32,
    iced.OpKind.IMMEDIATE8TO64: 64,
    iced.OpKind.IMMEDIATE32TO64: 64,
}
_BRANCH_KINDS = {iced.OpKind.NEAR_BRANCH16, iced.OpKind.NEAR_BRANCH32, iced.OpKind.NEAR_BRANCH64}
_MEMORY_KINDS = {
    iced.OpKind.MEMORY_SEG_SI: ("si", "ds"),
    iced.OpKind.MEMORY_SEG_ESI: ("esi", "ds"),
    iced.OpKind.MEMORY_SEG_RSI: ("rsi", "ds"),
    iced.OpKind.MEMORY_SEG_DI: ("di", "ds"),
    iced.OpKind.MEMORY_SEG_EDI: ("edi", "ds"),
    iced.OpKind.MEMORY_SEG_RDI: ("rdi", "ds"),
    iced.OpKind.MEMORY_ESDI: ("di", "es"),
    iced.OpKind.MEMORY_ESEDI: ("edi", "es"),
    iced.OpKind.MEMORY_ESRDI: ("rdi", "es"),
}


def _register_name(register: int) -> str | None:
    name = _REGISTER_NAMES.get(register, "none")
    return None if name == "none" else name


def _operand(decoded: iced.Instruction, index: int, image_address: bool = False) -> Operand:
    kind = decoded.op_kind(index)
    if kind == iced.OpKind.REGISTER:
        register = decoded.op_register(index)
        return Operand("register", iced.RegisterExt.size(register) * 8, reg=_register_name(register))
    if kind in _IMMEDIATE_WIDTHS:
        return Operand("immediate", _IMMEDIATE_WIDTHS[kind], imm=decoded.immediate(index), image_address=image_address)
    if kind in _BRANCH_KINDS:
        return Operand("branch", 32, imm=decoded.near_branch_target, image_address=image_address)
    if kind in _MEMORY_KINDS:
        base, segment = _MEMORY_KINDS[kind]
        return Operand("memory", iced.MemorySizeExt.size(decoded.memory_size) * 8, base=base, segment=segment, image_address=image_address)
    if kind == iced.OpKind.MEMORY:
        return Operand("memory", iced.MemorySizeExt.size(decoded.memory_size) * 8, base=_register_name(decoded.memory_base), index=_register_name(decoded.memory_index), scale=decoded.memory_index_scale, displacement=decoded.memory_displacement, segment=_register_name(decoded.memory_segment), image_address=image_address)
    if kind in {iced.OpKind.FAR_BRANCH16, iced.OpKind.FAR_BRANCH32}:
        return Operand("far_branch", 48, imm=((decoded.far_branch_selector & 0xFFFF) << 32) | (decoded.far_branch32 & 0xFFFFFFFF))
    raise X86DecodeError(f"Unsupported iced operand kind {_OP_KIND_NAMES.get(kind, kind)} at VA 0x{decoded.ip:08X}")


def _instruction(pe: PE32, decoded: iced.Instruction, offsets: iced.ConstantOffsets) -> Instruction:
    branch_target_rva = None
    if decoded.op_count and decoded.op_kind(0) in _BRANCH_KINDS:
        target = decoded.near_branch_target
        if pe.image_base <= target < pe.image_base + pe.size_of_image:
            branch_target_rva = target - pe.image_base
    instruction_rva = decoded.ip - pe.image_base
    displacement_relocated = offsets.has_displacement and offsets.displacement_size == 4 and instruction_rva + offsets.displacement_offset in pe.highlow_relocation_rvas
    immediate_relocated = offsets.has_immediate and offsets.immediate_size == 4 and instruction_rva + offsets.immediate_offset in pe.highlow_relocation_rvas
    second_immediate_relocated = offsets.has_immediate2 and offsets.immediate_size2 == 4 and instruction_rva + offsets.immediate_offset2 in pe.highlow_relocation_rvas
    operands = []
    immediate_index = 0
    for index in range(decoded.op_count):
        kind = decoded.op_kind(index)
        image_address = kind in _BRANCH_KINDS and branch_target_rva is not None
        if kind == iced.OpKind.MEMORY:
            image_address = displacement_relocated
        elif kind in _IMMEDIATE_WIDTHS:
            image_address = immediate_relocated if immediate_index == 0 else second_immediate_relocated
            immediate_index += 1
        operands.append(_operand(decoded, index, image_address))
    return Instruction(instruction_rva, decoded.len, _MNEMONIC_NAMES[decoded.mnemonic], _CODE_NAMES[decoded.code], tuple(operands), branch_target_rva, _FLOW_NAMES[decoded.flow_control], decoded.has_rep_prefix, decoded.has_repe_prefix, decoded.has_repne_prefix, decoded.is_invalid, _FORMATTER.format(decoded))


def _raw_for_rva(pe: PE32, rva: int) -> tuple[Section, bytes]:
    for section in pe.sections:
        if not section.executable or not section.raw_size:
            continue
        if section.virtual_address <= rva < section.virtual_address + section.raw_size:
            offset = section.raw_offset + rva - section.virtual_address
            end = min(section.raw_offset + section.raw_size, offset + 15)
            return section, pe.data[offset:end]
    raise X86DecodeError(f"Executable RVA 0x{rva:08X} is not backed by file data")


def _decode_at(pe: PE32, rva: int) -> Instruction:
    _, raw = _raw_for_rva(pe, rva)
    decoder = iced.Decoder(32, raw, ip=pe.image_base + rva)
    decoded = decoder.decode()
    return _instruction(pe, decoded, decoder.get_constant_offsets(decoded))


def _linear_decode(pe: PE32, section: Section) -> dict[int, Instruction]:
    raw = pe.data[section.raw_offset:section.raw_offset + section.raw_size]
    decoder = iced.Decoder(32, raw, ip=pe.image_base + section.virtual_address)
    instructions = {}
    for item in decoder:
        instructions[item.ip - pe.image_base] = _instruction(pe, item, decoder.get_constant_offsets(item))
    return instructions


def _code_pointer_seeds(pe: PE32) -> set[int]:
    image = pe.mapped_image()
    executable = [(pe.image_base + section.virtual_address, pe.image_base + section.virtual_address + section.mapped_size) for section in pe.sections if section.executable]
    seeds = {pe.entry_rva}
    for relocation in pe.relocations:
        if relocation.kind != 3 or relocation.rva + 4 > len(image):
            continue
        value = struct.unpack_from("<I", image, relocation.rva)[0]
        if any(begin <= value < end for begin, end in executable):
            seeds.add(value - pe.image_base)
    return seeds


def _successors(instruction: Instruction) -> tuple[int, ...]:
    target = instruction.branch_target_rva
    if instruction.invalid or instruction.flow in {"return", "interrupt", "exception", "xbegin_xabort_xend"}:
        return ()
    if instruction.flow == "unconditional_branch":
        return (target,) if target is not None else ()
    if instruction.flow == "conditional_branch":
        return (instruction.next_rva, target) if target is not None else (instruction.next_rva,)
    if instruction.flow == "call":
        return (instruction.next_rva, target) if target is not None else (instruction.next_rva,)
    return (instruction.next_rva,) if instruction.flow in {"next", "indirect_call"} else ()


def decode_reachable(pe: PE32, seeds: set[int] | None = None) -> tuple[Instruction, ...]:
    queue = deque(seeds or {pe.entry_rva})
    visited: dict[int, Instruction] = {}
    while queue:
        rva = queue.popleft()
        if rva in visited:
            continue
        try:
            instruction = _decode_at(pe, rva)
        except X86DecodeError:
            continue
        visited[rva] = instruction
        for successor in _successors(instruction):
            if successor not in visited:
                queue.append(successor)
    return tuple(item for _, item in sorted(visited.items()))


def decode_program(pe: PE32) -> X86Program:
    executable_sections = [section for section in pe.sections if section.executable and section.raw_size]
    if not executable_sections:
        raise X86DecodeError("PE image has no raw-backed executable sections")
    instruction_maps = {section.name: _linear_decode(pe, section) for section in executable_sections}
    by_rva = {rva: item for items in instruction_maps.values() for rva, item in items.items()}
    for exact in decode_reachable(pe, _code_pointer_seeds(pe)):
        rva = exact.rva
        existing = by_rva.get(rva)
        if existing is None or existing.size != exact.size or existing.code != exact.code:
            by_rva[rva] = exact
            for section in executable_sections:
                if section.virtual_address <= rva < section.virtual_address + section.raw_size:
                    instruction_maps[section.name][rva] = exact
                    break
    sections = tuple(DecodedSection(section, tuple(item for _, item in sorted(instruction_maps[section.name].items()))) for section in executable_sections)
    return X86Program(sections)
