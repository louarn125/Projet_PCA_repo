#include "jeton.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display_token(token tk){
    printf("la presentement la presentement");
    if(tk.type==SHORT_SPACE){
        printf("c'est un %d qui contient:%.4s/\n", tk.type, tk.data.space);
    }
    else{
        printf("c'est un %d qui contient:%s/\n", tk.type, tk.data.word);
    }
}

void display_token_tab(token_tab* tab){
    for(int i = 0; i<tab->taille; i++){
        printf("j'affiche le token n°%d\n",i);
        display_token(tab->tab[i]);
    }
}

int main(){

    hashtable * table_hash = create_hashtable(8);

    printf("test fonction de mise en memoire:\n");
    char* text = charger_texte("text.txt");
    printf("%s\n",text);
    char * text_attendu = "bonjour je suis un text de test.\nla un retour a la ligne\t\tici 2 tabulations";
    if(strcmp(text,text_attendu)){
        printf("ok\n");
    }else{printf("pas ok\n");}

    printf("test decoupage:\n");
    
    token_tab* tokenA = decoupage(table_hash,text);
    display_token_tab(tokenA);
    token_tab* tokenB = decoupage(table_hash,text_attendu);
    display_token_tab(tokenB);



    free(text);
    return 0;
}