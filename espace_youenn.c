#include "jeton.h"
#include "strhash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//hashtable * table_hash = create_hashtable(16);

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
    hashtable * table_hash = create_hashtable(16);

    token_tab* token_A;
    token_tab* token_B;

    char * text_A = charger_texte("fichierA.txt");
    char * text_B = charger_texte("fichierB.txt");
    if( text_A == NULL || text_B == NULL) return 1;

    
    token_A = decoupage(table_hash,text_A);
    token_B = decoupage(table_hash,text_B);
    if( token_A == NULL || token_B == NULL) return 1;

    /* int ** lg = (int**) malloc(sizeof(int*)*token_A->taille);

    if(lg == NULL) return 1;
    for(int i = 0; i<token_A->taille; i++){
        lg[i] = (int*) malloc(sizeof(int)*token_B->taille);
        if(lg[i] == NULL) return 1;
        for(int j = 0; j<token_B->taille; j++){
            lg[i][j] = calcul_lg(i,j,token_A,token_B);
            printf("[%03d]",lg[i][j]);
        }
        printf("\n");
    } */
    int longueur = calcul_lg(token_A->taille,token_B->taille,token_A,token_B);
    printf("%d",longueur);

    return 0;

}