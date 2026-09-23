# Opening Cutscene Subtitles

The opening story cutscene has 13 timed caption segments in Brazilian Portuguese. Speaker names are drawn in the upper black bar; dialogue uses up to two lines in the lower black bar. K. Rool uses green and Klump uses warm orange. The renderer uses the game's white IA8 font with language support, at 75% scale, through the engine font cache and F3DEX2 commands.

The existing overlay callbacks are preserved. Captions are restricted to the intro story maps and disappear outside that sequence. The clock excludes pauses and resets when leaving the intro; it does not depend on render frame rate. The release keeps the timings from the recording build reviewed by danilotec1-prog.

## Validation and limitations

Native checks cover all 13 cues, glyph coverage, upper/lower bar bounds, colour selection, display-list allocation, pauses, map transitions, replay, clock wrap and the original callbacks. All 43 generated text banks are checked against the packaged binary. These checks do not replace playing the final NRM in Rekongpiled.

Timing is based on elapsed intro time, rather than individual audio playback events. Loading stalls or modified cutscene playback may affect synchronization. Coverage is limited to the main spoken dialogue represented by the 13 cues; this is not a new caption track for every sound or every cutscene. Report synchronization problems with the game version and a recording.

## References

Overlay dispatch is adapted from Rainchus/dk64 (`code_8F4B0.c`); the game's font data and rendering conventions remain the visual basis. The existing project credits and license notices continue to apply.

Dialogue/context references: [DK64 quotes](https://www.mariowiki.com/List_of_Donkey_Kong_64_quotes) and the [cutscene video reference](https://www.youtube.com/watch?v=yJWGl6pX-ps&t=189s). Timing was calibrated using local gameplay recordings.
