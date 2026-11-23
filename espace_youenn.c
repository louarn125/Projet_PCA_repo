#include "jeton.h"
#include "strhash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plsc.h"

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

int ** calcul_lg_matrice(text* data){
    int ** matrice = (int**) malloc(sizeof(int*)*data->token_origine->taille+1);
    for(int i = 0;i<data->token_origine->taille+1;i++){
        matrice[i] = (int*) malloc(sizeof(int)*data->token_changed->taille+1);
        matrice[i][0] = 0;
    }
    for(int i = 0; i<data->token_changed->taille+1;i++){
        matrice[0][i] = 0;
    }


    int i = data->token_origine->taille;
    int j = data->token_changed->taille;
    int stop = 0;
    if(data->token_changed->tab[j].type == SHORT_SPACE && data->token_changed->tab[j].type == data->token_origine->tab[i].type){
        for(int k = 0; k < 4 || data->token_changed->tab[j].data.space[k] != '\0' || stop == 0;k++){
            if(data->token_changed->tab[j].data.space[k] == data->token_origine->tab[i].data.space[k]){
                stop = 1;
            }
        }
    }
    if(data->token_changed->tab[j].data.word == data->token_origine->tab[i].data.word || stop == 1){// cas d'égalité

    }else{
        
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

    
    int longueur = calcul_lg(token_A->taille,token_B->taille,token_A,token_B);
    printf("%d",longueur);

    return 0;

}