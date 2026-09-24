# Editing Supplementary Translations

The normal 43 text banks remain in `text_files/` and use the original language-mod converter. Supplementary translations continue the numbering in `text_files/`: files 43 and 44. They are processed separately and do not add ROM text banks.

## Messages

Edit `text_files/[43] - Extra Text.txt` in UTF-8. Each entry has a stable identifier followed by ` = ` and its translation:

```text
WELL_DONE = MANDOU BEM!
JETPAC_EXIT = SAIR@DO@JETPAC
SPEAKER_KLUMP = KLUMP:
```

Keep the identifiers. Preserve spaces, Jetpac's `@` spaces and printf placeholders such as `%d`, `%.3s` and `%02d`. Do not add quotes around the translation. Lines starting with `#` are comments. The Arcade column labels are separate entries so each stays over its numeric column. Speaker names are editable here; character colours remain in the renderer.

Fixed game string slots have byte limits, which the converter checks against `src/fixed_text.c`. The Arcade renderer supports a limited alphabet and accent set. Changing to another language may require additional font or layout work; moving text into a TXT file does not remove those engine limits.

## Opening subtitles

Edit `text_files/[44] - Intro Subtitles.txt`. Each cue has five fields, separated by `|`:

```text
239.30|244.38|KLUMP|VOSSA EXCELÊNCIA,|JÁ CUIDAMOS DE TUDO!
254.10|255.03|KLUMP|NÃO!|
```

Fields are start time, end time, speaker, first line and second line. Times are seconds on the mod's intro clock, not timestamps in a recording. Use a decimal point. Keep the final separator for an empty second line. Supported speakers are `KROOL` and `KLUMP`; cues must be chronological and must not overlap. Keep the existing times when only revising wording.

The converter checks encoding, font coverage, line width, speaker IDs and timing order. It cannot verify that a line matches the spoken audio; play the cutscene after changing timings. Do not use `|` inside dialogue. Use uppercase text supported by the current font.

## Generate and build

To regenerate supplementary data only, run from the repository root:

```sh
python text_converter/extra_converter.py
```

This writes `include/extra_texts.h` and `include/intro_cues.h`. Both generated headers are committed so an ordinary build can use them. Do not edit those headers manually.

To regenerate both the original text banks and supplementary data:

```sh
cd text_converter
python converter.py
cd ..
```

Then build and package using the existing build dependencies:

```sh
make
RecompModTool mod.toml path/to/output
```

Running `make` alone does not regenerate TXT edits. Run the converter first. The supplementary converter uses Python 3.9 or newer and only standard-library modules. It can be run from any working directory; the original bank converter still expects `text_converter/` as its working directory.

Converter checks can be run with:

```sh
python text_converter/test_extra_converter.py
```

After editing, commit the TXT files and regenerated headers together. Test the resulting `translation_ptbr.nrm` in the game before publishing. The TXT files are build inputs, not external files loaded dynamically by an installed NRM.
