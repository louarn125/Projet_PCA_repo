#include "jeton.h"
#include "strhash.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void display_char_tab(s_node * noeud){
    printf("%s",((char*) list_get_data(noeud)));
}

void affichage_hashtable(hashtable * table){
    for(int i = 0; i < table->taille;i++){
        printf("%d\n",i);
        display_list(table->elt[i].tab,display_char_tab);
    }
}

void display_token(token* tk){
    (tk->type==SHORT_SPACE?printf("%.4s\n", tk->data.space):printf("%s\n", tk->data.word));
}

void display_token_tab(token** tab, int taille){
    for(int i = 0; i<taille; i++){
        display_token(tab[i]);
    }
}

/**
 * Prends en paramètre un pointeur de hashtable, un pointeur de token, un pointeur de char(texte)
 * 
 */

/*
int decoupage2(hashtable* table, token** tab, char* text){
    int i = 0;
    int offset = 0;
    int tabId = 0;
    while(text[i]!='\0'){
        
        Dans cette boucle je dois :
        - Determiner la taille de la chaine a récuperer
        - Creer un token du bon type
        - lui ajouter ses valeurs (a l'aide de strncpy)
        - incrementer le offset apres chaque nouveau token
        
        int taille = 0;
        if(isalpha(text[i])){
            while(isalpha(text[i])){
                taille++;
                i++;
            }
            printf("mot ?\n");
            tab = realloc(tab, (tabId+1)*sizeof(token*));
            token* tk = (token*)malloc(sizeof(token));
            printf("etape 1\n");
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
            printf("mot c'est bon\n");
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
            printf("espace c'est bon \n");
        }
        else{
            i++;
        }
    }
    return tabId;
}
*/

int decoupage(hashtable* table, token** tab, int tailleTab, char* text){
    int car = 0;
    int taille;
    int type;
    int tTab = tailleTab;
    while(text[car]!='\0'){
        type = (isspace(text[car])?1:0);
        taille=0;
        while(isspace(text[car])==type){
            taille++;
            car++;
        }
        (type==0?printf("mot\n"):printf("espace\n"));

        token* tk = (token*)malloc(sizeof(token));
        if(tk!=NULL){
            if(type==1 && taille<=4){
                tk->type=SHORT_SPACE;
                tk->textOffset=car;
                strncpy(tk->data.space, text+car, taille);
            }
            else{
                char* mot = (char*)malloc((taille+1)*sizeof(char));
                if(mot!=NULL){
                    if(type==1){
                        tk->type=SPACE;
                    }
                    else{
                        tk->type=WORD;
                    }
                    tk->textOffset = car;
                    strncpy(mot, text+car, taille);
                    mot[taille]='\0';
                    tk->data.word=mot;
                }
            }
            token** temp = realloc(tab,(tTab+1)*sizeof(token*));
            if(temp!=tab){
                tab=temp;
                tTab++;
                tab[tTab]=tk;
            }
            else{
                free(tk->data.word);
                free(tk);
            }
        }
        car++;
        printf("fini\n");
    }
    return tTab;
}



int main(){
    hashtable* table = create_hashtable(10);
    token** tab = (token**)malloc(0*sizeof(token*));
    int taille;
    printf("probleme dans découpage ?\n");
    taille = decoupage(table, tab, 0, "test de decoupage d'un texte en jetons via la fontion decoupage");
    printf("affichage\n");
    affichage_hashtable(table);
    display_token_tab(tab, taille);

    return 0;
}