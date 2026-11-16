#include "jeton.h"
#include "strhash.h"
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
    int offset = 0;
    int tabId = 0;
    while(text[i]!='\0'){
        /*
        Dans cette boucle je dois :
        - Determiner la taille de la chaine a récuperer
        - Creer un token du bon type
        - lui ajouter ses valeurs (a l'aide de strncpy)
        - incrementer le offset apres chaque nouveau token
        */
        int taille = 0;
        if(isalpha(text[i])){
            while(isalpha(text[i])){
                taille++;
                i++;
            }
            tab = (token**)realloc(tab, (tabId+1)*sizeof(token*));
            token* tk = (token*)malloc(sizeof(token));
            if(tk!=NULL){
                char* temp = (char*)malloc((taille+1)*sizeof(char));
                if(temp!=NULL){
                    strncpy(temp, text[i-taille], taille);
                    tk->type = WORD;
                    tk->data.word = add_mot(table, temp);
                    tk->textOffset = offset;
                    offset++;
                    tab[tabId]=tk;
                    tabId
                    free(temp);
                }
            }
        }
        else if(isspace(text[i])){
            while(isspace(text[i])){
                taille++;
                i++;
            }
            token* tk = (token*)malloc(sizeof(token));
            if(tk!=NULL){
                if(taille<=4){
                    tk->type = SHORT_SPACE;
                    strncpy(tk->data.space, text[i-taille], taille);
                }
                else{
                    tk->type = SPACE;
                    char* temp = (char*)malloc((taille+1)*sizeof(char));
                    if(temp!=NULL){
                        strncpy(temp, text[i-taille], taille);
                        tk->data.word=add_mot(table, temp);
                        free(temp);
                    }
                }
                tk->textOffset = offset;
                offset++;
                tab[tabId]=tk;
            }
        }
        else{
            i++;
        }
    }
}
