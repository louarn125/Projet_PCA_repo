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

token_tab * decoupage(hashtable* table, char* text){
    int car = 0;
    int taille;
    int type;

    token_tab * tab = (token_tab*) malloc(sizeof(token_tab));
    if(tab == NULL) return NULL;

    tab->tab = (token*)malloc(sizeof(token));
    if(tab->tab == NULL){
        free(tab);
        return NULL;
    }
    tab->taille = 0;

    while(text[car]!='\0'){

        type=isspace(text[car]);
        taille=0;
        while(isspace(text[car])==type && text[car]!='\0'){
            taille++;
            car++;
        }
        token* tk = realloc(tab->tab,(tab->taille+1)*sizeof(token));
        if(tk!=NULL){
            tab->tab = tk;

            if(type>=1 && taille<=4){ // SHORT_SPACE
                tab->tab[tab->taille].type=SHORT_SPACE;
                tab->tab[tab->taille].textOffset=car;
                //tab->tab[tab->taille].data
                strncpy(tab->tab[tab->taille].data.space, text+car-taille, taille); // <- fout la merde
            }
            else{ // SPACE & WORD
                char* mot = (char*)malloc((taille+1)*sizeof(char)); 
                if(mot!=NULL){

                    if(type>=1){ // SPACE
                        tab->tab[tab->taille].type=SPACE;
                    }else{ // WORD
                        tab->tab[tab->taille].type=WORD;
                    }

                    tab->tab[tab->taille].textOffset = car;

                    strncpy(mot, text+car-taille, taille);
                    mot[taille]='\0';
                    char* temp_mot = add_mot(table,mot);
                    if(temp_mot == NULL){
                        free(tab->tab);
                        free(tab);
                        return NULL;
                    }
                    tab->tab[tab->taille].data.word=temp_mot;
                    free(mot);
                }
            }
            tab->taille++;
        }else{//realloc echoué
            free(tab->tab);
            free(tab);
            return NULL;
        }
    }
    return tab;
}