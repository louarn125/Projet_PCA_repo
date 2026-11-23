#include "jeton.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display_token(token tk){

    if(tk.type==SHORT_SPACE){
        printf("|%.4s|", tk.data.space);
    }
    else{
        printf("|%s|", tk.data.word);
    }
}

void display_token_tab(token_tab* tab){
    for(int i = 0; i<tab->taille; i++){
        //printf("j'affiche le token n°%d\n",i);
        display_token(tab->tab[i]);
    }
    printf("\n");
}

void compare_token(token_tab* tabA,token_tab* tabB){
    for(int i = 0; i<tabA->taille;i++){
        if(tabA->tab[i].type == SHORT_SPACE){
            int j = 0;
            while(tabA->tab[i].data.space[j] != '\0' || j<4){
                if(tabA->tab[i].data.space[j] != tabB->tab[i].data.space[j]){
                    printf("difference dans le token %d \n", i);
                    return;
                }j++;
            }
        }
        if(tabA->tab[i].data.word != tabB->tab[i].data.word){
            printf("difference dans le token %d \n", i);
            return;
        }
    }
    printf("aucune différence entre tokenA et tokenB\n");
}

void display_char_tab(s_node * noeud){
    printf("%s",((char*) list_get_data(noeud)));
}

void affichage_hashtable(hashtable * table){
    for(int i = 0; i < table->taille;i++){
        printf("%d:\n",i);
        display_list(table->elt[i].tab,display_char_tab);
    }
}

int main(){

    hashtable * table_hash = create_hashtable(8);
    
    printf("test fonction de mise en memoire:\n\n");
    char* text = charger_texte("text.txt");
    printf("text:==============================\n%s\n\n",text);
    char* text_bis = charger_texte("text.txt");
    printf("text_bis:==========================\n%s\n\n",text);
    char * text_attendu = "bonjour       je suis un text       de test.\nla un retour a la      ligne\nici 2 tabulations\0";
    printf("text_attendu:======================\n%s\n\n",text_attendu);
    char * text_attendu_modif = "bonjour       je suis un text       de text///.\nla un retour a la      ligne\nici 2 tabulations\0";
    printf("text_attendu_modif:================\n%s\n\n",text_attendu_modif);
    char* text_tab = charger_texte("tab.txt");
    printf("text_tab:==========================\n%s\n\n",text_tab);
    char* text_tab_attendu = "j'ai	besoin	d'un text		avec      des tabulations	donc					je le  créé\n\0";
    printf("text_tab_attendu:==================\n%s\n\n",text_tab);

    if(strcmp("text","text") == 0){
        printf("test de egalite ok\n");
    }else{printf("test de egalite pas ok\n");}

    if(strcmp(text,text_attendu) == 0){
        printf("text et text_attendu egaux\n");
    }else{printf("text et text_attendu pas egaux\n");}

    if(strcmp(text,text_bis) == 0){
        printf("text et text_bis egaux\n");
    }else{printf("text et text_bis pas egaux\n");}

    if(strcmp(text_tab,text_tab_attendu) == 0){
        printf("text_tab et text_tab_attendu egaux\n");
    }else{printf("text_tab et text_tab_attendu pas egaux\n");}

    printf("test decoupage:\n");
    
    token_tab* tokenA = decoupage(table_hash,text);
    printf("tokenA:\n");
    display_token_tab(tokenA);
    affichage_hashtable(table_hash);
    token_tab* tokenB = decoupage(table_hash,text_attendu);
    printf("tokenB:\n");
    display_token_tab(tokenB);
    affichage_hashtable(table_hash);
    token_tab* tokenC = decoupage(table_hash,text_attendu_modif);
    printf("tokenC:\n");
    display_token_tab(tokenC);
    affichage_hashtable(table_hash);
    token_tab* tokenD = decoupage(table_hash,text_tab);
    printf("tokenD:\n");
    display_token_tab(tokenD);
    affichage_hashtable(table_hash);
    
    printf("différence entre tokenA et tokenB:\n");
    compare_token(tokenA,tokenB);
    printf("différence entre tokenA et tokenC:\n");
    compare_token(tokenA,tokenC);
    printf("différence entre tokenA et tokenD:\n");
    compare_token(tokenA,tokenD);

    free(text);
    return 0;
}