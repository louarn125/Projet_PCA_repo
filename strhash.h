#ifndef _STRHASH_
#define _STRHASH_
#include "list.h"

typedef struct hashtable{
    s_node** tab;
    int taille;
} hashtable;

hashtable* create_hashtable(int taille); 
hashtable* destroy_hashtable(hashtable* tab); 
hashtable* free_hashtable_data(hashtable* tab); 
void add_mot(hashtable* tab, char* mot); 
void del_mot(hashtable* tab, char* mot); 
void display_stats(hashtable* tab);

#endif