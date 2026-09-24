# Brazilian Portuguese Translation

Brazilian Portuguese Translation of DK64

![Mod thumbnail](thumb.png)

## Opening Cutscene Subtitles

Version 1.0.3 adds Brazilian Portuguese subtitles for the main spoken dialogue in the opening story cutscene. Speaker names appear in the upper black bar, with dialogue below the picture. K. Rool uses green captions and Klump uses orange captions. See [subtitle notes](docs/INTRO_SUBTITLES.md) for implementation details and limitations.

## Installation
1. Download the latest `translation_ptbr.nrm` from [Releases](https://github.com/danilotec1-prog/RecompBrazilianPortuguese/releases).
2. Put the file in your DK64 Recompiled mods folder.
   - Example (Windows): `C:\Users\<YourUser>\AppData\Local\DK64Recompiled\mods`
3. Launch DK64 Rekongpiled 1.0.2 or newer and enable the mod from the mods menu. Disable other language mods and restart the game.

## Editing Translations

Opening subtitles and supplementary UI messages can be edited in UTF-8 TXT files in `text_files/[43] - Extra Text.txt` and `text_files/[44] - Intro Subtitles.txt`. See [editing instructions](docs/EDITING_TEXTS.md) for file formats, validation and regeneration. The original numbered text banks remain in `text_files/`.

## Build Requirements
- `clang`
- `ld.lld`
- `make`
- `RecompModTool` from [N64Recomp](https://github.com/N64Recomp/N64Recomp)

Notes:
- On macOS, Apple Clang is not enough for this target. Use an LLVM toolchain that supports MIPS and point `CC`/`LD` to it if needed.
- On Linux/macOS, ensure `zip` is installed for packaging workflows.

## Building from Source
Clone this repository and obtain the build dependencies separately:

```bash
git clone https://github.com/danilotec1-prog/RecompBrazilianPortuguese.git
cd RecompBrazilianPortuguese
git clone https://github.com/Rainchus/Dk64Syms.git Dk64Syms
git clone --branch recomp https://gitlab.com/Rainchus/dk64.git dk64_decomp
```

From the repository root:

```bash
make
```

This builds `build/mod.elf`.

Then package the mod:

```bash
RecompModTool mod.toml C:/path/to/DK64Recompiled/mods
```

PowerShell example:

```powershell
.\RecompModTool.exe .\mod.toml C:\Users\<YourUser>\AppData\Local\DK64Recompiled\mods
```

The produced mod file is named `translation_ptbr.nrm`.

## Project Layout
- `src/main.c`: Text and font replacement hooks.
- `src/text.c` and `src/font.c`: Generated text banks and font atlases.
- `font/` and `text_files/`: Font resources and Brazilian Portuguese game text.
- `mod.toml`: Mod metadata, target game id, and packaging inputs.
- `dk64_decomp/`: Decompiled DK64 source and headers used by the build.
- `Dk64Syms/`: Symbol files used by RecompModTool.

## Credits
Based on [RecompSpanish](https://github.com/theballaam96/RecompSpanish) by Ballaam. Brazilian Portuguese localization and review by [danilotec1-prog](https://github.com/danilotec1-prog).

AI (OpenAI Codex) was used as a support tool in developing tools for this mod. See [CREDITS.md](CREDITS.md) for full attribution and [license notices](LICENSES/README.md) for third-party notices.

## Feedback

Errors may still occur. Please report incorrect translations, font issues or other problems through [GitHub Issues](https://github.com/danilotec1-prog/RecompBrazilianPortuguese/issues), including a screenshot and where the issue occurred. Your feedback helps improve the mod.

