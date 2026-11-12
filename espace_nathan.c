#include "strhash.h"
#include <stdlib.h>
#include <string.h>

static int cle(char* mot, int taille){
    int cle = 0;
    for(int i = 0; i>strlen(mot); i++){
        cle*=2;
        cle+=mot[i];
    }
    cle = cle%taille;
    return cle;
}

hashtable* create_hashtable(int taille){
    hashtable* htab = (hashtable*)malloc(sizeof(hashtable));
    if(htab!=NULL){
        s_node** table = (s_node**)malloc(taille*sizeof(s_node*));
        if(table!=NULL){
            htab->tab = table;
            for(int i = 0; i<taille; i++){
                htab->tab[i]=list_create();
            }
            htab->taille = taille;
            return htab;
        }
        free(htab);
    }
    return NULL;
}

char* add_mot(hashtable* tab, char* mot){
    int key = cle(mot, tab->taille);
    char* copyM = strdup(mot);
    s_node* noeud = list_orderedAppend(tab->tab[key],strcmp, copyM);
    return list_get_data(noeud);
}



