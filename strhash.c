#include "strhash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

static int cle(char* mot, int taille){
    int cle = 0;
    for(int i = 0; i<strlen(mot); i++){
        cle*=2;
        cle+=mot[i];
    }
    cle = cle%taille;
    return cle;
}

/**
 * Prends un entier taille en paramètre
 * Retourne l'adresse d'une hashtable si tout s'est bien passé
 * Retourne NULL si au moins un malloc a échoué
 */
hashtable* create_hashtable(int taille){
    hashtable* htab = (hashtable*)malloc(sizeof(hashtable));
    if(htab!=NULL){
        element* elt = (element*)malloc(taille*sizeof(element));
        if(elt!=NULL){
            htab->elt = elt;
            for(int i = 0; i<taille; i++){
                htab->elt[i].tab=list_create();
                htab->elt[i].taille=0;
            }
            htab->taille = taille;
            return htab;
        }
        free(htab);
    }
    return NULL;
}

/**
 * Prends en parametre une addresse de hastable et un mot en char*
 * Ajoute le mot dans la table de hachage au bon endroit et renvoi son adresse
 * Ou si le mot existe déjà, renvoi l'adresse du mot déjà existant
 */
char* add_mot(hashtable* tab, char* mot){
    int key = cle(mot, tab->taille);
    char* copyM = strdup(mot);
    s_node* noeud = list_orderedAppend(&(tab->elt[key].tab),strcmp_list, copyM);
    if(noeud!=NULL){
        if(list_get_data(noeud)==copyM){
            tab->elt[key].taille++;
        }
        return list_get_data(noeud);
    }
    return mot;
}

/**
 * Prends une adresse de hashtable en paramètre
 * Affiche les statistiques de la table de hachage
 * Ne retourne rien
 */
void display_stats(hashtable* table){
    if(table!=NULL){
        int nb_elt = table->elt[0].taille, min = table->elt[0].taille, max = table->elt[0].taille;
        double ec_type=nb_elt*nb_elt, somme=table->taille;
        for(int i = 1; i<table->taille; i++){
            int taille = table->elt[i].taille;
            if(taille>max){max=taille;}
            if(taille<min){min=taille;}
            nb_elt+=taille;
            ec_type+=taille*taille;
        }
        double moy = nb_elt/somme;
        ec_type = sqrt(ec_type/somme-moy*moy);
        printf("Statistiques de la table de hachage :\n");
        printf("------------------------------------");
        printf("Nombre total de mots : %d\n",nb_elt);
        printf("------------------------------------");
        printf("Tailles de listes de mots\n-- MIN : %d\n-- MAX : %d\n",min , max);
        printf("------------------------------------");
        printf("Écart type :%f\n",ec_type);
    }
    else{
        printf("La table de hachage n'existe pas");
    }
}

/**
 * Prends en paramètre un pointeur de hashtable
 * détruit entièrement la hashtable, les liste qui la composent et les données stockées dans les listes.
 * Ne renvois rien
 */
void destroy_hashtable(hashtable* table){
    free_hashtable_data(table);
    free(table->elt);
    free(table);
}

/**
 * Prends en paramètre un pointeur de hashtable
 * Libère les données stockées dans les listes de la table
 * Ne renvois rien
 */
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

/**
 * Prends en paramètre un pointeur de hastable et un pointeur de char (mot)
 * Supprime le mot de la table s'il existe
 * Ne renvois rien
 */
void del_mot(hashtable* table, char* mot){
    int key = cle(mot,table->taille);
    char * temp;
    s_node * cur = table->elt[key].tab;
    while(cur != NULL && strcmp((char*)list_get_data(cur),(char*)mot)){
        cur = list_next(cur);
    }
    if(cur != NULL){
        temp = list_get_data(cur);
        table->elt[key].tab = list_remove(table->elt[key].tab,temp);
        table->elt[key].taille-=1;
    }
}

static int strcmp_list(s_node* noeud, void* mot){
    return strcmp(((char*)list_get_data(noeud)),((char*)mot));
}