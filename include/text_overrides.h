#ifndef PTBR_TEXT_OVERRIDES_H
#define PTBR_TEXT_OVERRIDES_H
/* Latin-1 strings, shared by runtime code and native mapping tests. */
static int ptbr_text_equal(const unsigned char *a, const char *b) {
    if (!a) return 0;
    while (*a && *a == (unsigned char)*b) { ++a; ++b; }
    return *a == (unsigned char)*b;
}
static unsigned char *ptbr_long_message(unsigned char *text) {
    if (ptbr_text_equal(text,"WELL DONE!") || ptbr_text_equal(text,"MUITO BEM!"))
        return (unsigned char*)"BOM TRABALHO!";
    if (ptbr_text_equal(text,"LAP BONUS") || ptbr_text_equal(text,"B\324NUS VOLTA"))
        return (unsigned char*)"B\324NUS DE VOLTA";
    return text;
}
static unsigned char *ptbr_arcade_message(unsigned char *text) {
    if (ptbr_text_equal(text,"YOUR NAME WAS") || ptbr_text_equal(text,"SEU NOME FOI")) return (unsigned char*)"SEU NOME FOI";
    if (ptbr_text_equal(text,"CREDIT 00") || ptbr_text_equal(text,"FICHAS 00")) return (unsigned char*)"CR\311DITOS 00";
    if (ptbr_text_equal(text,"EXIT DK ARCADE") || ptbr_text_equal(text,"SAIR DO ARCADE")) return (unsigned char*)"SAIR DO ARCADE DK";
    if (ptbr_text_equal(text,"HOW HIGH CAN YOU GET ?") || ptbr_text_equal(text,"ATE ONDE VOCE CHEGA ?")) return (unsigned char*)"AT\311 ONDE VOC\312 CONSEGUE CHEGAR ?";
    if (ptbr_text_equal(text,"INSERT COIN") || ptbr_text_equal(text,"USE A FICHA")) return (unsigned char*)"INSIRA UMA FICHA";
    if (ptbr_text_equal(text,"PLAYER    COIN") || ptbr_text_equal(text,"JOGADOR FICHA")) return (unsigned char*)"JOGADOR    FICHA";
    return text;
}
#endif
