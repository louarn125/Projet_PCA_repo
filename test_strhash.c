#include "strhash.h"
#include <stdio.h>
#include <string.h>

display_char_tab(s_node * noeud){
    printf("%s",((char*) list_get_data(noeud)));
}

void affichage_hashtable(hashtable * table){
    for(int i = 0; i < table->taille;i++){
        display_list(table->elt[i].tab,display_char_tab);
    }
}

int main(){
    printf("Test lib strhash.h\n");
    hashtable* table_hash = create_hashtable(8);
    printf("affichage de la table de hachage\n");
    affichage_hashtable(table_hash);
//ajout de mot type
    printf("ajout du mot bonjour\n");
    char* str1 = add_mot(table_hash,"bonjour");
    printf("affichage du mot: '%s' et de sont adresse: '%d'\n",str1,str1);
//affichage de hashtable type
    printf("affichage de la table de hachage\n");
    affichage_hashtable(table_hash);

    printf("ajout du mot salut\n");
    char* str2 = add_mot(table_hash,"salut");
    printf("affichage du mot: '%s' et de sont adresse: '%d'\n",str1,str1);
    
    printf("ajout du mot voiture\n");
    char* str3 = add_mot(table_hash,"voiture");
    printf("affichage du mot: '%s' et de sont adresse: '%d'\n",str1,str1);

    printf("ajout du mot manger\n");
    char* str4 = add_mot(table_hash,"manger");
    printf("affichage du mot: '%s' et de sont adresse: '%d'\n",str1,str1);

    printf("ajout du mot chemin\n");
    char* str5 = add_mot(table_hash,"chemin");
    printf("affichage du mot: '%s' et de sont adresse: '%d'\n",str1,str1);

    printf("ajout du mot bonjour\n");
    char* str6 = add_mot(table_hash,"bonjour");
    printf("affichage du mot: '%s' et de sont adresse: '%d'\n",str1,str1);

    return 0;
}