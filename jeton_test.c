#include "jeton.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    printf("test fonction de mise en memoire:\n");
    char* text = charger_texte("text.txt");
    printf("%s\n",text);
    char * text_attendu = "bonjour je suis un text de test.\nla un retour a la ligne\t\tici 2 tabulations";
    if(strcmp(text,text_attendu)){
        printf("ok\n");
    }else{printf("pas ok\n");}

    printf("test decoupage:\n");
    





    free(text);
    return 0;
}