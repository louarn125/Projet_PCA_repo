#include "list.h"

struct _list_node{
    void * val;
    s_node * next;
};

s_node* list_create(){
    return NULL;
}

s_node* list_insert(s_node* head, void* val){
    s_node* new_head = (s_node*)malloc(sizeof(s_node));
    list_set_data(new_head, val);
    new_head->next = head;
    return new_head;
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
    
