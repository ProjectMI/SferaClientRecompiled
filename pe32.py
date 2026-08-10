from __future__ import annotations

import hashlib
import math
import struct
from dataclasses import dataclass
from pathlib import Path


class PEFormatError(RuntimeError):
    pass


@dataclass(frozen=True)
class DataDirectory:
    rva: int
    size: int


@dataclass(frozen=True)
class Section:
    name: str
    virtual_size: int
    virtual_address: int
    raw_size: int
    raw_offset: int
    characteristics: int
    entropy: float

    @property
    def mapped_size(self) -> int:
        return max(self.virtual_size, self.raw_size)

    @property
    def readable(self) -> bool:
        return bool(self.characteristics & 0x40000000)

    @property
    def writable(self) -> bool:
        return bool(self.characteristics & 0x80000000)

    @property
    def executable(self) -> bool:
        return bool(self.characteristics & 0x20000000)


@dataclass(frozen=True)
class ImportSymbol:
    dll: str
    iat_rva: int
    ordinal: int | None
    hint: int | None
    name: str | None


@dataclass(frozen=True)
class ExportSymbol:
    ordinal: int
    rva: int
    name: str | None
    forwarder: str | None


@dataclass(frozen=True)
class Relocation:
    rva: int
    kind: int


@dataclass(frozen=True)
class DebugRecord:
    kind: int
    timestamp: int
    size: int
    raw_offset: int
    codeview_signature: str | None
    pdb_path: str | None
    guid_age: str | None


def shannon_entropy(data: bytes) -> float:
    if not data:
        return 0.0
    counts = [0] * 256
    for byte in data:
        counts[byte] += 1
    length = len(data)
    return -sum((count / length) * math.log2(count / length) for count in counts if count)


class PE32:
    DIRECTORY_EXPORT = 0
    DIRECTORY_IMPORT = 1
    DIRECTORY_SECURITY = 4
    DIRECTORY_BASERELOC = 5
    DIRECTORY_DEBUG = 6

    def __init__(self, path: Path):
        self.path = path
        self.data = path.read_bytes()
        self.sha256 = hashlib.sha256(self.data).hexdigest()
        self._parse_headers()
        self.imports = self._parse_imports()
        self.exports = self._parse_exports()
        self.relocations = self._parse_relocations()
        self.highlow_relocation_rvas = frozenset(item.rva for item in self.relocations if item.kind == 3)
        self.debug_records = self._parse_debug_records()

    def _u16(self, offset: int) -> int:
        self._require(offset, 2)
        return struct.unpack_from("<H", self.data, offset)[0]

    def _u32(self, offset: int) -> int:
        self._require(offset, 4)
        return struct.unpack_from("<I", self.data, offset)[0]

    def _require(self, offset: int, size: int) -> None:
        if offset < 0 or size < 0 or offset + size > len(self.data):
            raise PEFormatError(f"Out-of-range read: offset={offset:#x}, size={size:#x}")

    def _parse_headers(self) -> None:
        if len(self.data) < 0x40 or self.data[:2] != b"MZ":
            raise PEFormatError("Missing DOS MZ header")
        pe_offset = self._u32(0x3C)
        self._require(pe_offset, 24)
        if self.data[pe_offset:pe_offset + 4] != b"PE\0\0":
            raise PEFormatError("Missing PE signature")
        coff = pe_offset + 4
        self.machine = self._u16(coff)
        self.section_count = self._u16(coff + 2)
        self.timestamp = self._u32(coff + 4)
        optional_size = self._u16(coff + 16)
        self.characteristics = self._u16(coff + 18)
        optional = coff + 20
        self._require(optional, optional_size)
        magic = self._u16(optional)
        if magic != 0x10B:
            raise PEFormatError(f"Only PE32 is supported, optional magic={magic:#x}")
        self.linker_major = self.data[optional + 2]
        self.linker_minor = self.data[optional + 3]
        self.entry_rva = self._u32(optional + 16)
        self.image_base = self._u32(optional + 28)
        self.section_alignment = self._u32(optional + 32)
        self.file_alignment = self._u32(optional + 36)
        self.size_of_image = self._u32(optional + 56)
        self.size_of_headers = self._u32(optional + 60)
        self.subsystem = self._u16(optional + 68)
        self.dll_characteristics = self._u16(optional + 70)
        self.stack_reserve = self._u32(optional + 72)
        self.stack_commit = self._u32(optional + 76)
        directory_count = min(self._u32(optional + 92), 16)
        directory_offset = optional + 96
        self.directories = []
        for index in range(directory_count):
            entry = directory_offset + index * 8
            self.directories.append(DataDirectory(self._u32(entry), self._u32(entry + 4)))
        while len(self.directories) < 16:
            self.directories.append(DataDirectory(0, 0))
        section_table = optional + optional_size
        self.sections = []
        for index in range(self.section_count):
            offset = section_table + index * 40
            self._require(offset, 40)
            raw_name = self.data[offset:offset + 8].split(b"\0", 1)[0]
            name = raw_name.decode("ascii", errors="replace")
            virtual_size = self._u32(offset + 8)
            virtual_address = self._u32(offset + 12)
            raw_size = self._u32(offset + 16)
            raw_offset = self._u32(offset + 20)
            characteristics = self._u32(offset + 36)
            raw = self.data[raw_offset:raw_offset + raw_size] if raw_offset + raw_size <= len(self.data) else b""
            self.sections.append(Section(name, virtual_size, virtual_address, raw_size, raw_offset, characteristics, shannon_entropy(raw)))
        if self.size_of_headers > len(self.data):
            raise PEFormatError("SizeOfHeaders exceeds file size")

    def directory(self, index: int) -> DataDirectory:
        return self.directories[index]

    def rva_to_offset(self, rva: int, size: int = 1) -> int:
        if rva < self.size_of_headers:
            self._require(rva, size)
            return rva
        for section in self.sections:
            start = section.virtual_address
            end = start + section.raw_size
            if start <= rva and rva + size <= end:
                offset = section.raw_offset + rva - start
                self._require(offset, size)
                return offset
        raise PEFormatError(f"RVA not backed by file data: rva={rva:#x}, size={size:#x}")

    def read_c_string_rva(self, rva: int, limit: int = 4096) -> str:
        offset = self.rva_to_offset(rva)
        end = self.data.find(b"\0", offset, min(len(self.data), offset + limit))
        if end < 0:
            raise PEFormatError(f"Unterminated string at RVA {rva:#x}")
        return self.data[offset:end].decode("ascii", errors="replace")

    def _parse_imports(self) -> list[ImportSymbol]:
        directory = self.directory(self.DIRECTORY_IMPORT)
        if directory.rva == 0 or directory.size == 0:
            return []
        imports = []
        descriptor_rva = directory.rva
        for _ in range(4096):
            offset = self.rva_to_offset(descriptor_rva, 20)
            original_first_thunk, timestamp, forwarder, name_rva, first_thunk = struct.unpack_from("<IIIII", self.data, offset)
            if original_first_thunk == timestamp == forwarder == name_rva == first_thunk == 0:
                return imports
            dll = self.read_c_string_rva(name_rva)
            lookup_rva = original_first_thunk or first_thunk
            for index in range(1_000_000):
                thunk = self._u32(self.rva_to_offset(lookup_rva + index * 4, 4))
                if thunk == 0:
                    break
                iat_rva = first_thunk + index * 4
                if thunk & 0x80000000:
                    imports.append(ImportSymbol(dll, iat_rva, thunk & 0xFFFF, None, None))
                    continue
                name_offset = self.rva_to_offset(thunk, 3)
                hint = self._u16(name_offset)
                end = self.data.find(b"\0", name_offset + 2, min(len(self.data), name_offset + 4096))
                if end < 0:
                    raise PEFormatError(f"Unterminated import name at RVA {thunk:#x}")
                name = self.data[name_offset + 2:end].decode("ascii", errors="replace")
                imports.append(ImportSymbol(dll, iat_rva, None, hint, name))
            descriptor_rva += 20
        raise PEFormatError("Import descriptor limit exceeded")

    def _parse_exports(self) -> list[ExportSymbol]:
        directory = self.directory(self.DIRECTORY_EXPORT)
        if directory.rva == 0 or directory.size < 40:
            self.export_module_name = None
            return []
        offset = self.rva_to_offset(directory.rva, 40)
        fields = struct.unpack_from("<IIHHIIIIIII", self.data, offset)
        _, _, _, _, name_rva, ordinal_base, function_count, name_count, functions_rva, names_rva, ordinals_rva = fields
        self.export_module_name = self.read_c_string_rva(name_rva) if name_rva else None
        names_by_index = {}
        for index in range(name_count):
            symbol_name_rva = self._u32(self.rva_to_offset(names_rva + index * 4, 4))
            ordinal_index = self._u16(self.rva_to_offset(ordinals_rva + index * 2, 2))
            names_by_index[ordinal_index] = self.read_c_string_rva(symbol_name_rva)
        exports = []
        directory_end = directory.rva + directory.size
        for index in range(function_count):
            function_rva = self._u32(self.rva_to_offset(functions_rva + index * 4, 4))
            if function_rva == 0:
                continue
            forwarder = self.read_c_string_rva(function_rva) if directory.rva <= function_rva < directory_end else None
            exports.append(ExportSymbol(ordinal_base + index, function_rva, names_by_index.get(index), forwarder))
        return exports

    def _parse_relocations(self) -> list[Relocation]:
        directory = self.directory(self.DIRECTORY_BASERELOC)
        if directory.rva == 0 or directory.size == 0:
            return []
        relocations = []
        cursor = 0
        while cursor + 8 <= directory.size:
            block_rva = directory.rva + cursor
            offset = self.rva_to_offset(block_rva, 8)
            page_rva, block_size = struct.unpack_from("<II", self.data, offset)
            if block_size < 8 or cursor + block_size > directory.size:
                raise PEFormatError(f"Invalid relocation block at RVA {block_rva:#x}")
            entry_count = (block_size - 8) // 2
            for index in range(entry_count):
                value = self._u16(self.rva_to_offset(block_rva + 8 + index * 2, 2))
                kind = value >> 12
                within_page = value & 0x0FFF
                if kind != 0:
                    relocations.append(Relocation(page_rva + within_page, kind))
            cursor += block_size
        return relocations

    def _parse_debug_records(self) -> list[DebugRecord]:
        directory = self.directory(self.DIRECTORY_DEBUG)
        if directory.rva == 0 or directory.size < 28:
            return []
        records = []
        count = directory.size // 28
        base = self.rva_to_offset(directory.rva, count * 28)
        for index in range(count):
            offset = base + index * 28
            _, timestamp, _, _, kind, size, _, raw_offset = struct.unpack_from("<IIHHIIII", self.data, offset)
            signature = None
            pdb_path = None
            guid_age = None
            if kind == 2 and size >= 4 and raw_offset + size <= len(self.data):
                payload = self.data[raw_offset:raw_offset + size]
                signature = payload[:4].decode("ascii", errors="replace")
                if payload[:4] == b"RSDS" and len(payload) >= 24:
                    guid = payload[4:20].hex()
                    age = struct.unpack_from("<I", payload, 20)[0]
                    pdb_path = payload[24:].split(b"\0", 1)[0].decode("utf-8", errors="replace")
                    guid_age = f"{guid}:{age}"
                elif payload[:4] == b"NB10" and len(payload) >= 16:
                    age = struct.unpack_from("<I", payload, 12)[0]
                    pdb_path = payload[16:].split(b"\0", 1)[0].decode("utf-8", errors="replace")
                    guid_age = f"NB10:{age}"
            records.append(DebugRecord(kind, timestamp, size, raw_offset, signature, pdb_path, guid_age))
        return records

    def mapped_image(self) -> bytearray:
        image = bytearray(self.size_of_image)
        image[:self.size_of_headers] = self.data[:self.size_of_headers]
        for section in self.sections:
            if section.raw_size == 0:
                continue
            source_start = section.raw_offset
            source_end = source_start + section.raw_size
            target_start = section.virtual_address
            target_end = target_start + section.raw_size
            if source_end > len(self.data) or target_end > len(image):
                raise PEFormatError(f"Section {section.name} exceeds file or image bounds")
            image[target_start:target_end] = self.data[source_start:source_end]
        return image
