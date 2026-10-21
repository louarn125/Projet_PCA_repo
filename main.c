#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
  s_node* list = list_create();
  printf("-------------------- TEST list_insert() ------------------------\n");
  int v = 2;
  void* val = &v; 
  s_node* test_insert = list_insert(list, val);
  int* res = (int*) list_get_data(test_insert);
  printf("valeur de tête attendue : 2, valeur : %d\n", *res);
  printf("----------------------------------------------------------------\n");
  return 0;
}
