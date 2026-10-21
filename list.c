#include "list.h"



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
    while(iteration->next != NULL && compare(iteration,param)){
        iteration = iteration->next;
    }
    if(iteration == NULL){

    }
}
s_node* list_create(){
    return NULL;
}

s_node* list_insert(s_node* head, void* val){
    s_node* new_head = (s_node*)malloc(sizeof(s_node));
    if(new_head!=NULL){
        list_set_data(new_head, val);
        new_head->next = head;
        return new_head;
    }
    else{
        return head;
    }
}
/*
s_node* list_append(s_node* head, void* val){
    s_node* new_queue = (s_node*)malloc(sizeof(s_node));
    s_node* cur_queue = head;
    while(cur_queue->next!=NULL){
        cur_queue = cur_queue->next;
    }
    cur_queue->next = new_queue;
    list_set_data(new_queue, val);
    return head;
}
*/
    
