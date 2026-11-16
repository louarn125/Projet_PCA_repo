#include "strhash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* charger_texte(const char* nom_fichier){
    FILE * fichier = fopen(nom_fichier,"r");
    
    fclose(fichier);
}