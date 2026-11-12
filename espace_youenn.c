#include "strhash.h"
#include <stdlib.h>

hashtable* destroy_hashtable(hashtable* table){
    free_hashtable_data(table);
    free(table->tab);
    free(table);
}

void free_hashtable_data(hashtable* table){
    for(int i = 0; i<table->taille;i++){
        s_node * head = table->tab[i];
        while(head != NULL){
            free(list_get_data(head));
            head = list_next(head);
        }
        list_destroy(table->tab[i]);
        table->tab[i] = NULL;
    }
}