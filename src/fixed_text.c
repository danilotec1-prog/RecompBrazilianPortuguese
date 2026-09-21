/* Fixed UI messages omitted from the text banks.
 * Addresses are symbol-relative for overlay relocation. The existing per-frame event is used instead of vanilla function hooks.
 * Overlay code signatures and pointer bounds are checked before dispatch. Original bytes AND zero padding must
 * match before writing; unexpected versions or other mods are left alone.
 * No persistent "already patched" flag: overlays may be reloaded at any time.
 */
#ifndef PTBR_HOST_TEST
#include "modding.h"
#else
#define RECOMP_CALLBACK(mod, event)
#endif

__attribute__((noinline)) static void ptbr_replace_slot(unsigned char *dst, const char *expected,
                              unsigned int expected_size, const char *replacement,
                              unsigned int replacement_size, unsigned int capacity) {
    unsigned int i;
    if (expected_size > capacity || replacement_size > capacity) return;
    for (i = 0; i < expected_size; ++i)
        if (dst[i] != (unsigned char)expected[i]) return;
    for (; i < capacity; ++i)
        if (dst[i] != 0) return;
    for (i = 0; i < replacement_size; ++i)
        dst[i] = (unsigned char)replacement[i];
    for (; i < capacity; ++i) dst[i] = 0;
}

#define PTBR_SLOT(dst, old, translated, capacity) \
    ptbr_replace_slot(dst, old, sizeof(old), translated, sizeof(translated), capacity)

extern unsigned char D_global_asm_80755378[];
static void ptbr_global_asm_strings(void) {
    PTBR_SLOT(D_global_asm_80755378 + 0x0, "GAME OVER", "FIM DE JOGO", 12);
}

extern unsigned char critter_RODATA_START[];
static void ptbr_critter_strings(void) {
    PTBR_SLOT(critter_RODATA_START + 0x1E0, "WELL DONE!", "MUITO BEM!", 12);
    PTBR_SLOT(critter_RODATA_START + 0x1EC, "TIME OUT!", "SEM TEMPO!", 12);
}

extern unsigned char multiplayer_RODATA_START[];
static void ptbr_multiplayer_strings(void) {
    PTBR_SLOT(multiplayer_RODATA_START + 0x4, "BAD LUCK", "QUE AZAR", 12);
}

extern unsigned char bonus_RODATA_START[];
static void ptbr_bonus_strings(void) {
    PTBR_SLOT(bonus_RODATA_START + 0x594, "SCORE", "PONTOS", 8);
    PTBR_SLOT(bonus_RODATA_START + 0x59C, "LAP BONUS", "B\324NUS VOLTA", 12);
}

extern unsigned char arcade_RODATA_START[];
static void ptbr_arcade_strings(void) {
    PTBR_SLOT(arcade_RODATA_START + 0x0, "NAME %.3s", "NOME %.3s", 12);
    PTBR_SLOT(arcade_RODATA_START + 0x10, "REGI TIME <%02d>", "TEMPO <%02d>", 20);
    PTBR_SLOT(arcade_RODATA_START + 0x24, "YOUR NAME WAS", "SEU NOME FOI", 16);
    PTBR_SLOT(arcade_RODATA_START + 0x34, "REGISTERED.", "REGISTRADO.", 12);
    PTBR_SLOT(arcade_RODATA_START + 0x40, "NAME REGISTRATION", "REGISTRO DE NOME", 20);
    PTBR_SLOT(arcade_RODATA_START + 0xAC, "CREDIT 00", "FICHAS 00", 12);
    PTBR_SLOT(arcade_RODATA_START + 0xBC, "HIGH SCORE", "RECORDE", 12);
    PTBR_SLOT(arcade_RODATA_START + 0xE0, "GAME OVER", "FIM DE JOGO", 12);
    PTBR_SLOT(arcade_RODATA_START + 0xEC, "RETURN", "VOLTAR", 8);
    PTBR_SLOT(arcade_RODATA_START + 0xF4, "DELETE HISCORE", "ZERAR RECORDE", 16);
    PTBR_SLOT(arcade_RODATA_START + 0x104, "EXIT DK ARCADE", "SAIR DO ARCADE", 16);
    PTBR_SLOT(arcade_RODATA_START + 0x11C, "HOW HIGH CAN YOU GET ?", "ATE ONDE VOCE CHEGA ?", 24);
    PTBR_SLOT(arcade_RODATA_START + 0x154, "INSERT COIN", "USE A FICHA", 12);
    PTBR_SLOT(arcade_RODATA_START + 0x160, "PLAYER    COIN", "JOGADOR FICHA", 16);
    PTBR_SLOT(arcade_RODATA_START + 0x17C, "RANK  SCORE  NAME", "POS. PONTOS NOME", 20);
}

extern unsigned char jetpac_RODATA_START[];
static void ptbr_jetpac_strings(void) {
    PTBR_SLOT(jetpac_RODATA_START + 0x28, "JETPAC GAME SELECTION", "JETPAC - MENU DO JOGO", 24);
    PTBR_SLOT(jetpac_RODATA_START + 0x40, "1@@@1@PLAYER@GAME", "1@@@1@JOGADOR", 20);
    PTBR_SLOT(jetpac_RODATA_START + 0x54, "2@@@2@PLAYER@GAME", "2@@@2@JOGADORES", 20);
    PTBR_SLOT(jetpac_RODATA_START + 0x68, "3@@@KEYBOARD", "3@@@TECLADO", 16);
    PTBR_SLOT(jetpac_RODATA_START + 0x78, "4@@@KEMPSTON@JOYSTICK", "4@@@CONTROLE@KEMPSTON", 24);
    PTBR_SLOT(jetpac_RODATA_START + 0x90, "5   START GAME", "5   JOGAR", 16);
    PTBR_SLOT(jetpac_RODATA_START + 0xC4, "RETURN", "VOLTAR", 8);
    PTBR_SLOT(jetpac_RODATA_START + 0xCC, "DELETE@HISCORE", "ZERAR@RECORDE", 16);
    PTBR_SLOT(jetpac_RODATA_START + 0xDC, "EXIT@@JETPAC", "SAIR@@JETPAC", 16);
    PTBR_SLOT(jetpac_RODATA_START + 0xEC, "RAREWARE COIN COLLECTED", "MOEDA RAREWARE OBTIDA", 24);
    PTBR_SLOT(jetpac_RODATA_START + 0x104, "GAME OVER PLAYER %d", "FIM DE JOGO - J%d", 20);
}

/* Only inspect loaded N64 RDRAM. The signature identifies the overlay even
 * when multiple overlays share the same address; a stale relocation is not
 * sufficient permission to modify memory. No writes are made to code.
 */
static int ptbr_signature_matches(const unsigned char *data,
                                  const unsigned char *signature,
                                  unsigned int size) {
    unsigned int i;
    for (i = 0; i < size; ++i) if (data[i] != signature[i]) return 0;
    return 1;
}
static int ptbr_overlay_matches(const unsigned char *rodata, unsigned int offset,
                                const unsigned char *signature) {
    __UINTPTR_TYPE__ address = (__UINTPTR_TYPE__)rodata;
    if (address < 0x80000000UL + offset || address >= 0x80800000UL) return 0;
    return ptbr_signature_matches(rodata - offset + 0x100, signature, 32);
}
static const unsigned char ptbr_signature_global_asm[32] = {0x25,0x4A,0x8E,0x20,0x25,0x6B,0x40,0x00,0x25,0x8C,0xDF,0x10,0x25,0xCE,0xDF,0x10,0x25,0xAD,0xDE,0xF0,0x27,0x18,0x01,0x70,0x25,0xEF,0x40,0x00,0x25,0x08,0x01,0x70};
static const unsigned char ptbr_signature_critter[32] = {0x24,0x05,0x00,0x7B,0x24,0x03,0x00,0x80,0x24,0x05,0x00,0x81,0x90,0x8F,0x00,0x02,0x00,0x00,0x30,0x25,0x3C,0x01,0x40,0xA0,0x19,0xE0,0x00,0x0C,0x00,0x00,0x00,0x00};
static const unsigned char ptbr_signature_multiplayer[32] = {0x24,0x84,0x00,0x08,0xAC,0x4F,0x00,0x04,0x00,0x80,0x18,0x25,0x3C,0x19,0x00,0x78,0x37,0x39,0xFF,0x50,0x3C,0x18,0xFA,0x00,0xAC,0x78,0x00,0x00,0xAC,0x79,0x00,0x04};
static const unsigned char ptbr_signature_bonus[32] = {0x0C,0x1C,0x9C,0x1F,0x00,0x00,0x30,0x25,0x24,0x04,0x00,0x02,0x24,0x05,0x00,0x40,0x0C,0x1C,0x9C,0x1F,0x00,0x00,0x30,0x25,0x24,0x04,0x00,0x03,0x24,0x05,0x00,0x40};
static const unsigned char ptbr_signature_arcade[32] = {0x8C,0x84,0xA0,0x48,0x8F,0xA4,0x00,0x2C,0x0C,0x1C,0x11,0x21,0x00,0x00,0x28,0x25,0x3C,0x0B,0x80,0x74,0x91,0x6B,0x44,0xEC,0x24,0x01,0x00,0x03,0x00,0x40,0x20,0x25};
static const unsigned char ptbr_signature_jetpac[32] = {0x8C,0x84,0xA0,0x48,0x8F,0xA4,0x00,0x2C,0x0C,0x1C,0x11,0x21,0x00,0x00,0x28,0x25,0x3C,0x0B,0x80,0x74,0x91,0x6B,0x44,0xEC,0x24,0x01,0x00,0x04,0x00,0x40,0x20,0x25};

RECOMP_CALLBACK("*", dk64recomp_every_frame)
void ptbr_fixed_text_frame(void) {
    if (ptbr_overlay_matches(D_global_asm_80755378, 0x15A078, ptbr_signature_global_asm)) ptbr_global_asm_strings();
    if (ptbr_overlay_matches(critter_RODATA_START, 0x5FB0, ptbr_signature_critter)) ptbr_critter_strings();
    if (ptbr_overlay_matches(multiplayer_RODATA_START, 0x3040, ptbr_signature_multiplayer)) ptbr_multiplayer_strings();
    if (ptbr_overlay_matches(bonus_RODATA_START, 0x9940, ptbr_signature_bonus)) ptbr_bonus_strings();
    if (ptbr_overlay_matches(arcade_RODATA_START, 0x26840, ptbr_signature_arcade)) ptbr_arcade_strings();
    if (ptbr_overlay_matches(jetpac_RODATA_START, 0xA9D0, ptbr_signature_jetpac)) ptbr_jetpac_strings();
}
