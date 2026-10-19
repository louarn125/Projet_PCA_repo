#include "list.h"

struct _list_node{
    void * val;
    s_node * next;
};

/**
 * prend un noeud en argument et retourne sa valeur
 */
void * list_get_data(s_node * node){
    if(node != NULL) return node->val;
    else return NULL;
}

/**
 * prend un noeud en argument et une valeur et met la valeur dans le noeud
 */
void list_set_data(s_node * node, void * data){
    if(node != NULL) node->val = data;
    return;
}

s_node * list_orderedAppend(s_node ** head, int(*compare)(s_node *,void *), void * param){
    s_node * iteration = *head;
    while(iteration != NULL && compare(iteration,param)){

    }
}