#include "strhash.h"
#include <stdlib.h>
#include <string.h>

void destroy_hashtable(hashtable* table){
    free_hashtable_data(table);
    free(table->elt->tab);
    free(table);
}

void free_hashtable_data(hashtable* table){
    for(int i = 0; i<table->taille;i++){
        s_node * head = table->elt[i].tab;
        while(head != NULL){
            free(list_get_data(head));
            head = list_next(head);
        }
        list_destroy(table->elt[i].tab);
        table->elt[i].tab = NULL;
    }
}

void del_mot(hashtable* table, char* mot){
    char* temp = add_mot(table,mot);
    int tkt = cle(temp,table->taille);
    list_remove(table->elt[tkt].tab,temp);
}