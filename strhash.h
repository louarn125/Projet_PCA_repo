#ifndef _STRHASH_
#define _STRHASH_
#include "list.h"

typedef struct element{
    s_node** tab;
    int taille;
} element;

typedef struct hashtable{
    element elt;
    int taille;
} hashtable;

static int cle(char* mot, int taille);
hashtable* create_hashtable(int taille); 
void destroy_hashtable(hashtable* tab); 
void free_hashtable_data(hashtable* tab); 
char* add_mot(hashtable* tab, char* mot); 
void del_mot(hashtable* tab, char* mot); 
void display_stats(hashtable* tab);

#endif