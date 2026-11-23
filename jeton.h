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

typedef struct token_tab{
    token * tab;
    int taille;
}token_tab;

char* charger_texte(const char* nom_fichier);
token_tab * decoupage(hashtable* table, char* text);
//int decoupage2(hashtable* table, token***, int tailleTab, char* text);

#endif