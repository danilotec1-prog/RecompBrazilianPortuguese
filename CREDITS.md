# Credits and Provenance

## Brazilian Portuguese Localization

- **[danilotec1-prog](https://github.com/danilotec1-prog)**: project direction, Brazilian cultural adaptation, review, in-game testing and approval of visual changes.
- **OpenAI Codex (AI)**: a support tool used to develop tools for creating the mod, including programming assistance, resource extraction and comparison, auditing, font adjustments and initial translation assistance. Human review and testing are provided by the maintainer.

## Reused Technical Framework

**Ballaam / theballaam96 and contributors — [RecompSpanish](https://github.com/theballaam96/RecompSpanish).** This project directly adapts its C hooks for runtime text-bank and font replacement, text converters and extractors, font atlas generator, initial build structure, manifest, header references and initial font resources. The README follows the upstream layout.

Local changes include Brazilian Portuguese localization, numerical text-bank ordering, encoding and string termination fixes, case-safe X/x filenames, atlas dimensions, character offsets and additional accented characters. The upstream CC0 notice is preserved unchanged in `Licence-CC0.txt` on GitHub and `LICENSES/CC0.txt` in the source package.

## Translation References

- **Ballaam / theballaam96 and contributors — [RecompFrench](https://github.com/theballaam96/RecompFrench) and [RecompGerman](https://github.com/theballaam96/RecompGerman)**: French and German text, font and thumbnail comparisons. Spanish text was also used as a reference.
- **Original English text and European fonts**: extracted from locally supplied game ROMs for reference.

## Game, Artwork and Thumbnail

**Rare / Nintendo and the respective rights holders**: Donkey Kong 64, characters, original text, fonts and artwork. Upstream CC0 does not place game assets or trademarks in the public domain.

The thumbnail was composed programmatically from a Brazilian flag and the DK portrait recovered from the common areas of the Spanish, French and German mod thumbnails. Character artwork: Rare / Nintendo. Thumbnail composition reference: Ballaam.

Existing European font characters are preserved where available. Additional Brazilian Portuguese characters were prepared with Codex assistance and reviewed by the maintainer; these additions are not represented as original Rare artwork.

## Runtime, Symbols and Tools

- **[DK64 Rekongpiled team](https://dk64recomp.com/)**: native port and mod runtime support.
- **[N64Recomp contributors](https://github.com/N64Recomp/N64Recomp)**: recompilation infrastructure and RecompModTool.
- **Rainchus and contributors — [Dk64Syms](https://github.com/Rainchus/Dk64Syms) and [DK64 decompilation](https://gitlab.com/Rainchus/dk64)**: symbols and technical reference. Local build used Dk64Syms revision `91107c0`.
- **[n64decomp/libreultra](https://github.com/n64decomp/libreultra)**: 2.0I headers used in the local build.
- **[Zig](https://ziglang.org/), [LLVM/LLD](https://llvm.org/) and [llvm-mingw](https://github.com/mstorsjo/llvm-mingw)**: MIPS compilation and linking.
- **[Python](https://www.python.org/) and [Pillow](https://python-pillow.github.io/)**: text, image and packaging tools.

External tools retain their own licenses. Their executables and full distributions are not included. Attribution does not imply endorsement, partnership or official participation. This independent fan project does not distribute ROMs. Please contact the maintainer to request attribution corrections.
