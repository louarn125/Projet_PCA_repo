#include "list.h"
#include <stdio.h>

int main(){
  s_node* list = list_create();
  int v = 2;
  void* val = &v; 
  s_node* test_insert = list_insert(list, val);
  printf("valeur de tête attendue : 1, valeur : %d\n", test_insert->val);
  return EXIT_SUCCESS;
}
