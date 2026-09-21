# Build Notes

Generated C text banks and font atlases are included. The upstream Makefile requires MIPS-capable Clang, LLD, Make, RecompModTool and the dependencies specified in `.gitmodules`. Obtain those dependencies separately before building. The standard Makefile path must be validated in the maintainer's environment.

The local preparation used Python and Pillow, Zig 0.14.1, LLD from llvm-mingw 20260908, Dk64Syms revision 91107c0, libreultra 2.0I headers and RecompModTool. Executables and dependency distributions are not included.

Compiler settings: MIPS2, ABI32, no PIC, `_LANGUAGE_C`, `MIPS`, `F3DEX_GBI`. Linking uses `mod.ld` and `--emit-relocs --unresolved-symbols=ignore-all`.

To regenerate font atlases, run `python joiner.py` from `font/`. Only PNGs referenced by `config.json` are used. Unicode filenames avoid X/x collisions on Windows. `y_offsets` preserves the text baseline without compressing letters.

Yellow atlas: RGBA5551, 72 x 28, 4032 bytes per page. White atlas: IA8, 256 x 16. Dimensions are generated in `font.h` and used by the loader.
