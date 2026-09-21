# Text and Font Audit

## Text Banks

The local US ROM contains **43 files** in pointer table 12 at master table `0x101C50`. All indices 0–42 are covered. English: 652 entries; mod: 656 entries, including four additional entries from European bank 26. This establishes bank coverage, not complete coverage of everything displayed by the game.

## Hardcoded Messages

| Text | Evidence | Status |
|---|---|---|
| GAME OVER | RAM 0x80755378; reference in func_global_asm_80713B40 at 0x80713C38 | Implemented in 1.0.1 |
| WELL DONE! | critter overlay, RAM 0x8002A190; reference in func_critter_80029118 at 0x80029504 | Implemented in 1.0.1 |
| TIME OUT! | critter overlay | Implemented in 1.0.1 |
| BAD LUCK | multiplayer overlay | Implemented in 1.0.1 |
| LAP BONUS | bonus overlay | Implemented in 1.0.1 |
| HIGH SCORE, GAME OVER, INSERT COIN, EXIT DK ARCADE | arcade overlay | Implemented in 1.0.1 |
| JETPAC GAME SELECTION, START GAME, GAME OVER PLAYER %d | jetpac overlay | Implemented in 1.0.1 |

Translated bank entries do not replace duplicate strings embedded in code. Longer replacements require redirected pointers or calls with separate buffers. Static references were identified; not all runtime call paths were traced. Textures and 3D objects containing words still require visual auditing.

## Opening Cutscene

No subtitle switch was found in the documented game options. Missing captions for the spoken opening are also reported for the original game; this audit does not establish a Rekongpiled-specific regression or verify every regional version. Adding subtitles requires transcription, translation, timing and pause/skip handling, plus gameplay testing. This is not implemented.

References: [Nintendo manual](https://www.nintendo.com/eu/media/downloads/games_8/emanuals/nintendo_8/Manual_Nintendo64_DonkeyKong64_EN.pdf), [original-game caption report](https://www.reddit.com/r/nintendohelp/comments/1tx1ggj/donkey_kong_64_closed_captions/).

## Font Review

The maintainer confirmed that the unwanted detail on E was resolved after the tilde update. The yellow C-cedilla now uses the original C at full size and baseline, with the cedilla extending below it. Package checks do not replace visual validation of this latest adjustment in game. 

Version 1.0.1 adds 32 bounded replacements using the existing frame event. The maintainer confirmed that the corrected package works in game; exhaustive coverage and layout testing remain ongoing.
