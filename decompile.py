from __future__ import annotations

import argparse
import sys
from pathlib import Path

from pe32 import PE32, PEFormatError


def choose_input(root: Path, explicit: str | None) -> Path:
    if explicit:
        path = Path(explicit)
        return path if path.is_absolute() else root / path
    candidates = sorted(item for item in root.iterdir() if item.is_file() and item.suffix.lower() == ".exe")
    if len(candidates) != 1:
        names = ", ".join(item.name for item in candidates) or "none"
        raise RuntimeError(f"Expected exactly one EXE in {root}, found: {names}")
    return candidates[0]


def main() -> int:
    parser = argparse.ArgumentParser(description="Generate a Win32 structured-IR interpreter project from a PE32/x86 image")
    parser.add_argument("folder", nargs="?", default=".", help="Folder containing one EXE and its DLL dependencies")
    parser.add_argument("--input", help="EXE filename when the folder contains multiple executables")
    args = parser.parse_args()
    root = Path(args.folder).resolve()
    try:
        from emit_cpp import generate

        target = choose_input(root, args.input)
        pe = PE32(target)
        if pe.machine != 0x14C:
            raise RuntimeError(f"Only PE32/i386 is supported, machine=0x{pe.machine:04X}")
        generate(pe, root, root / "out")
    except (OSError, RuntimeError, PEFormatError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1
    print(root / "out")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
