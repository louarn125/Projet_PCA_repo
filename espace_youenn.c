#include "jeton.h"
#include "strhash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//hashtable * table_hash = create_hashtable(16);

int calcul_lg(int i, int j, token ** text_A, token ** text_B){

    if(i == 0 || j == 0){
        return 0;
    }
    if(text_A[i]==text_B[j]){
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

    token ** token_A = (token **)malloc(sizeof(token*));
    token ** token_B = (token **)malloc(sizeof(token*));
    if( token_A == NULL || token_B == NULL) return 1;

    char * text_A = charger_texte("fichierA.txt");
    char * text_B = charger_texte("fichierB.txt");
    if( text_A == NULL || text_B == NULL) return 1;

    printf("test\n");
    int taille_A = decoupage(table_hash,token_A,text_A);
    int taille_B = decoupage(table_hash,token_B,text_B);
    printf("test2\n");
    int ** lg = (int**) malloc(sizeof(int*)*taille_A);
    if(lg == NULL) return 1;
    for(int i = 0; i<taille_A; i++){
        lg[i] = (int*) malloc(sizeof(int)*taille_B);
        if(lg[i] == NULL) return 1;
        for(int j = 0; j<taille_B; j++){
            lg[i][j] = calcul_lg(i,j,token_A,token_B);
            printf("[%03d]",lg[i][j]);
        }
        printf("\n");
    }

    return 0;

}