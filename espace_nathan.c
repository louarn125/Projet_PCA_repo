#include "strhash.h"
#include <stdlib.h>

hashtable* create_hashtable(int taille){
    hashtable* htab = (hashtable*)malloc(sizeof(hashtable));
    if(htab!=NULL){
        s_node** table = (s_node**)malloc(taille*sizeof(s_node*));
        if(table!=NULL){
            htab->tab = table;
            htab->taille = taille;
            return htab;
        }
        free(htab);
    }
    return NULL;
}