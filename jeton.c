#include "strhash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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