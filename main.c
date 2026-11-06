#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * fonction d'affichage d'entier:
 * prend en argument un noeud de liste
 * affiche sur la sortie standart la valeur du noeud en argument.
 */
void display_int(s_node * noeud){
    printf("%d",(*(int*) noeud->val));
}

/**
 * fonction de comparaison d'entier:
 * prend en argument un noeud de liste et une valeur data
 * renvoi 1 si la valeur du noeud est supérieure a data
 * renvoi 0 si la valeur du noeud est égal à data
 * renvoi -1 si la valeur du noeud est inférieure à data
 * renvoi 2 si la valeur du noeud et/ou data est NULL
 */
int comparer_int(s_node* node, void* data){
  int* val1 = (int*)list_get_data(node);
  int* val2 = (int*)data;
  return (*val1)-(*val2);
}

int main(){
  s_node* list = list_create();
  printf("-------------------- TEST list_insert() ------------------------\n");
  int v = 2;
  void* val = &v; 
  printf("ajout de %d:\n",v);
  list = list_insert(list, val);
  display_list(list, display_int);
  int v2 = 1;
  printf("ajout de %d:\n",v2);
  list = list_insert(list, &v2);
  display_list(list, display_int);
  printf("-------------------- TEST list_append() ------------------------\n");
  int v3 = 3;
  printf("ajout de %d:\n",v3);
  list = list_append(list, &v3);
  display_list(list, display_int);
  int v4 = 0;
  printf("ajout de %d:\n",v4);
  list = list_append(list, &v4);
  display_list(list,display_int);
  printf("-------------------- TEST list_next() --------------------------\n");
  int v5 = 23;
  printf("ajout de %d:\n",v5);
  list = list_insert(list, &v5);
  display_list(list,display_int);
  printf("deplacement\n");
  list = list_next(list);
  display_list(list,display_int);
  printf("-------------------- TEST list_orderedAppend() -----------------\n");
  int v6 = 17;
  int v7 = 53;
  int v8 = 2;
  int v9 = 26;
  int v10 = 11;
  s_node* list2 = list_create();
  s_node ** temp_list = &list2;
  printf("list d'origine:\n");
  display_list(*temp_list,display_int);
  printf("ajout dans l'ordre: %d, %d, %d, %d, %d\n",v6,v7,v8,v9,v10);
  list_orderedAppend(temp_list, comparer_int, &v6);
  display_list(*temp_list,display_int);
  list_orderedAppend(temp_list, comparer_int, &v7);
  display_list(*temp_list,display_int);
  list_orderedAppend(temp_list, comparer_int, &v8);
  display_list(*temp_list,display_int);
  list_orderedAppend(temp_list, comparer_int, &v9);
  display_list(*temp_list,display_int);
  list_orderedAppend(temp_list, comparer_int, &v10);
  display_list(*temp_list,display_int);
  printf("-------------------- TEST list_remove() ------------------------\n");
  printf("list d'origine:\n");
  display_list(*temp_list,display_int);
  printf("suppression de %d:\n",v6);
  list_remove(*temp_list,&v6);
  display_list(*temp_list,display_int);
  printf("-------------------- TEST list_head_remove() -------------------\n");
  printf("list d'origine:\n");
  display_list(*temp_list,display_int);
  s_node* v_sup1 = list_headRemove(*temp_list);
  *temp_list = v_sup1;
  printf("liste:\n");
  display_list(*temp_list,display_int);
  printf("-------------------- TEST list_destroy() -----------------------\n");
  printf("list d'origine:\n");
  display_list(*temp_list,display_int);
  printf("suppression de la liste:\n");
  list_destroy(*temp_list);
  temp_list = NULL;
  printf("----------------------------------------------------------------\n");
  return 0;
}
