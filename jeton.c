#include "strhash.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TAILLE_TEXT 256

char* charger_texte(const char* nom_fichier){

    FILE * fichier = fopen(nom_fichier,"r");
    assert(fichier != NULL);
    if(fichier == NULL){
        return NULL;
    }

    char * text = (char *) malloc(sizeof(char));
    if(text == NULL){
        fclose(fichier);
        return NULL;
    }
    
    char buffer[TAILLE_TEXT+1];
    buffer[TAILLE_TEXT] = '\0';
    unsigned long int pos = 0;
    int temp;
    char * temp_text;
    
    while(!feof(fichier)){
        temp = fread(buffer,sizeof(char),TAILLE_TEXT,fichier);
        temp_text = (char *)realloc(text,sizeof(char)*(pos+temp));
        if(temp_text == NULL){
            fclose(fichier);
            free(text);
            return NULL;
        }else{text = temp_text;}
        strncpy(&(text[pos]),buffer,temp);
        pos += TAILLE_TEXT;

    }
    fclose(fichier);
    return text;
}