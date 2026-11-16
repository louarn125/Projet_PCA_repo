#include "jeton.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


/**
 * Prends en paramètre un pointeur de hashtable, un pointeur de token, un pointeur de char(texte)
 * 
 */
void decoupage(hashtable* table, token** tab, char* text){
    int i = 0;
    while(text[i]!='\0'){
        /*
        Dans cette boucle je dois :
        - Identifier le type du token
        - Creer un objet token du bon type
        - Remplir l'objet token jusqu'a trouver un caractère du mauvais type (boucle)
        - incrémentation de i
        - fin de boucle
        */
        if(isalpha(text[i])){
            token
        }
    }
}
