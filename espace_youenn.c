#include "strhash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* charger_texte(const char* nom_fichier){
    FILE * fichier = fopen(nom_fichier,"r");
    if(fichier == NULL){
        return NULL;
    }
    char * text = (char *) malloc(256*sizeof(char));
    if(text == NULL){
        fclose(fichier);
        return NULL;
    }
    char buffer[256];
    unsigned long int taille = 256;
    int temp = 0;

    while(temp = fread(buffer,sizeof(char),256,fichier) != EOF){
        
        text = (char *)realloc(text,taille);
        if(text == NULL){
            fclose(fichier);
            return NULL;
        }
    }

    fclose(fichier);
}