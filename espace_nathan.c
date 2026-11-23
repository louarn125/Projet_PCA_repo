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
    printf("la presentement la presentement");
    if(tk->type==SHORT_SPACE){
        printf("c'est un %d qui contient %.4s /\n", tk->type, tk->data.space);
    }
    else{
        printf("c'est un %d qui contient %s /\n", tk->type, tk->data.word);
    }
}

void display_token_tab(token** tab, int taille){
    for(int i = 0; i<taille; i++){
        printf("j'affiche le token n°%d\n",i);
        display_token(tab[i]);
    }
}
/*
int decoupage2(hashtable* table, token*** tab, int tailleTab, char* text){
    int car = 0;
    int taille;
    int type;
    int tTab = tailleTab;
    while(text[car]!='\0'){
        printf("%d\n", car);
        printf("%d", isspace(text[car]));
        if(isspace(text[car])){
            type=isspace(text[car]);
        }
        else{
            type=0;
        }
        taille=0;
        while(isspace(text[car])==type && text[car]!='\0'){
            taille++;
            car++;
        }
        printf("%d\n", type);
        if(type==0){
            printf("mot\n");
        }
        else{
            printf("espace\n");
        }

        token* tk = (token*)malloc(sizeof(token));
        if(tk!=NULL){
            if(type>=1 && taille<=4){
                tk->type=SHORT_SPACE;
                tk->textOffset=car;
                printf("%d",taille);
                strncpy(tk->data.space, text+car-taille, taille);
                printf("laisse moi dormir ah zebi");
            }
            else{
                char* mot = (char*)malloc((taille+1)*sizeof(char));
                if(mot!=NULL){
                    if(type>=1){
                        tk->type=SPACE;
                        printf("type : %d\n",tk->type);
                    }
                    else{
                        tk->type=WORD;
                    }
                    tk->textOffset = car;
                    strncpy(mot, text+car-taille, taille);
                    mot[taille]='\0';
                    printf("%s\n",mot);
                    char* temp = add_mot(table, mot);
                    if(temp!=NULL){
                        tk->data.word=temp;
                    }
                    else{
                        free(mot);
                        mot=NULL;
                        temp=NULL;
                    }
                }
            }
            token** temp = realloc(*tab,(tTab+1)*sizeof(token*));
            if(temp!=NULL){
                printf("je suis ici");
                *tab=temp;
                (*tab)[tTab]=tk;
                printf("je suis la\n");
                if((*tab)[tTab]->type==SHORT_SPACE){
                    printf("%.4sok\n", (*tab)[tTab]->data.space);
                }
                else{
                    printf("%sok\n", (*tab)[tTab]->data.word);
                }
                tTab++;
            }
            else{
                free(tk->data.word);
                free(tk);
            }
        }
        printf("fini-------------------\n");
    }
    printf("%p\n",*tab);
    return tTab;
}
*/

int calcul_lg(int i, int j, token_tab* text_A, token_tab* text_B){
    if(i == 0 || j == 0){
        return 0;
    }
    if(text_A->tab[i].data.word == text_B->tab[j].data.word){
        return calcul_lg(i-1,j-1,text_A,text_B)+1;
    }else{
        int a = calcul_lg(i-1,j,text_A,text_B);
        int b = calcul_lg(i,j-1,text_A,text_B);
        if(a>b)return a;
        else return b;
    }
}

int main(){
    /*
    hashtable* table = create_hashtable(10);
    token** tab = (token**)malloc(0*sizeof(token*));
    token*** res = &tab;
    int taille;
    char* texte = charger_texte("fichierA.txt");
    printf("probleme dans découpage ?\n");
    taille = decoupage2(table, res, 0, texte );
    printf("affichage\n");
    affichage_hashtable(table);
    printf("%p\n",*res);
    display_token_tab(*res, taille);
    */

    hashtable * table_hash = create_hashtable(16);

    token_tab* token_A;
    token_tab* token_B;

    char * text_A = charger_texte("text.txt");
    char * text_B = charger_texte("tab.txt");
    if( text_A == NULL || text_B == NULL) return 1;

    
    token_A = decoupage(table_hash,text_A);
    token_B = decoupage(table_hash,text_B);
    if( token_A == NULL || token_B == NULL) return 1;

    int ** lg = (int**) malloc(sizeof(int*)*token_A->taille);
    for(int i = 0; i<token_A->taille; i++){
        lg[i] = (int*) malloc(sizeof(int)*token_B->taille);
    }

    for(int i = 0; i<token_A->taille; i++){
        for(int j = 0; j<token_B->taille; j++){
            printf("[%3d] ", lg[i][j]);
        }
        printf("\n");
    }

    return 0;
}