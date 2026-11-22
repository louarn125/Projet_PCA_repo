#include "strhash.h"
#include "jeton.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define TAILLE_TEXT 256

char* charger_texte(const char* nom_fichier){

    FILE * fichier = fopen(nom_fichier,"r");
    if(fichier == NULL){
        return NULL;
    }

    int retour1 = fseek(fichier,0,SEEK_END);
    if(retour1 != 0){
        fclose(fichier);
        return NULL;
    }

    long int taille = ftell(fichier);

    retour1 = fseek(fichier,0,SEEK_SET);
    if(retour1 != 0){
        fclose(fichier);
        return NULL;
    }

    char * text = (char *) malloc(taille*sizeof(char));
    if(text == NULL){
        fclose(fichier);
        return NULL;
    }
    
    long int temp = fread(text,sizeof(char),taille,fichier);
    if(temp != taille){
        fclose(fichier);
        free(text);
        return NULL;
    }

    fclose(fichier);
    return text;
}

int decoupage(hashtable* table, token** tab, char* text){
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
                    strncpy(temp, text+(i-taille), taille);
                    temp[taille]='\0';
                    tk->type = WORD;
                    tk->data.word = add_mot(table, temp);
                    tk->textOffset = offset;
                    offset++;
                    tab[tabId]=tk;
                    tabId++;
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
                    strncpy(tk->data.space, text+(i-taille), taille);
                }
                else{
                    tk->type = SPACE;
                    char* temp = (char*)malloc((taille+1)*sizeof(char));
                    if(temp!=NULL){
                        strncpy(temp, text+(i-taille), taille);
                        temp[taille]='\0';
                        tk->data.word=add_mot(table, temp);
                        free(temp);
                    }
                }
                tk->textOffset = offset;
                offset++;
                tab[tabId]=tk;
                tabId++;
            }
        }
        else{
            i++;
        }
    }
    return tabId;
}