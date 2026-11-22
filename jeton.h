#ifndef _CHARGETEXT_
#define _CHARGETEXT_
#include "strhash.h"

typedef struct token {
    enum { WORD, SHORT_SPACE, SPACE, ERASE, INSERT , REPLACE, EMPTY } type ;
    int textOffset;
    union {
    char * word;
    char space[4];
    } data ;
}token;

char* charger_texte(const char* nom_fichier);
int decoupage(hashtable* table, token** tab, int tailleTab, char* text);

#endif