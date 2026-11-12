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
        element* elt = (element*)malloc(taille*sizeof(element));
        if(elt!=NULL){
            htab->elt = elt;
            for(int i = 0; i<taille; i++){
                htab->elt[i].tab=list_create();
                htab->elt[i];
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
    s_node* noeud = list_orderedAppend(&(tab->elt[key]),strcmp, copyM);
    return list_get_data(noeud);
}

void display_stats(hashtable* table){
    int nb_elt = 1, min = table->elt[0].taille, max = table->elt[0].taille;
    double ec_type=min*min, somme=1;
    for(int i = 1; i<table->taille; i++){
        int taille = table->elt[i].taille;
        if(taille>max){max=taille;}
        if(taille<min){min=taille;}
        nb_elt+=taille;
        somme++;
        ec_type+=taille*taille;
    }
    double moy = nb_elt/somme;
    ec_type = (ec_type/somme)-(moy*moy);
    printf("Statistiques de la table de hachage :\n");
    printf("------------------------------------");
    printf("Nombre total de mots : %d\n",nb_elt);
    printf("------------------------------------");
    printf("Tailles de listes de mots\n-- MIN : %d\n-- MAX : %d\n",min , max);
    printf("------------------------------------");
    printf("Écart type :\n",ec_type);
}

