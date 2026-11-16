#include "strhash.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TAILLE_TEXT 256

char* charger_texte(const char* nom_fichier){
    printf("%s\n",nom_fichier);
    fflush(stdout);
    FILE * fichier = fopen(nom_fichier,"r");
    printf("testouverture\n");
    assert(fichier != NULL);
    if(fichier == NULL){
        return NULL;
    }
    printf("test1\n");
    fflush(stdout);
    char * text = (char *) malloc(sizeof(char));
    if(text == NULL){
        fclose(fichier);
        return NULL;
    }
    printf("test2\n");
    char buffer[TAILLE_TEXT+1];
    buffer[TAILLE_TEXT] = '\0';
    unsigned long int pos = 0;
    int temp;
    char * temp_text;
    printf("test3\n");
    while((temp = fread(buffer,sizeof(char),TAILLE_TEXT,fichier)) < TAILLE_TEXT){
        temp_text = (char *)realloc(text,sizeof(char)*(pos+TAILLE_TEXT));
        if(temp_text == NULL){
            fclose(fichier);
            free(text);
            return NULL;
        }else{text = temp_text;}
        printf("realloc reussi\n");
        strncpy(&(text[pos]),buffer,TAILLE_TEXT);
        pos += TAILLE_TEXT;

    }
    fclose(fichier);
    return text;
}