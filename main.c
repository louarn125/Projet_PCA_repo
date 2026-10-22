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
  display_list(test_insert, display_int);
  int v2 = 1;
  test_insert = list_insert(test_insert, &v2);
  display_list(test_insert, display_int);
  printf("-------------------- TEST list_append() ------------------------\n");
  int v3 = 3;
  test_insert = list_append(test_insert, &v3);
  display_list(test_insert, display_int);
  int v4 = 0;
  test_insert = list_append(test_insert, &v4);
  display_list(test_insert,display_int);
  
  printf("----------------------------------------------------------------\n");
  return 0;
}
