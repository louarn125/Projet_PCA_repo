#include "strhash.h"

hashtable* destroy_hashtable(hashtable* table){
    free_hashtable_data(table);
    free(table->tab);
    free(table);
}

hashtable* free_hashtable_data(hashtable* table){
    for(int i = 0; i<table->taille;i++){
        table->tab[i];
        
    }
}