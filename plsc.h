#ifndef _PLSC_
#define _PLSC_
#include "jeton.h"

typedef struct text{
    token_tab* token_origine;
    char* text_origine;
    token_tab* token_changed;
    char* text_changed;
    hashtable* table_hash;
}text;

text* init_text(const char* origine, const char* changed);
int ** calcul_lg_matrice(text);

#endif