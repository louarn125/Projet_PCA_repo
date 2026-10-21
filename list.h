#ifndef _LISTE_
#define _LISTE_

typedef struct _list_node{
    void * val;
    struct _list_node * next;
} s_node;

s_node * list_create(void);
void * list_get_data(s_node * node);
void list_set_data(s_node * node, void * data);
s_node * list_insert(s_node * head, void * data);
s_node * list_append(s_node * head, void * data);
s_node * list_orderedAppend(s_node ** head, int(*compare)(s_node *,void *), void * param);
s_node * list_remove(s_node * head, void * data);
s_node * list_headRemove(s_node * head);
s_node * list_next(s_node * node);
void list_destroy(s_node * head);
void displaylist(s_node * head, void(*display)(s_node*));

#endif