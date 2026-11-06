#include "list.h"
#include <stdio.h>
#include <stdlib.h>

s_node* list_create(){
    return NULL;
}

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

s_node * list_next(s_node * node){
    return node->next;
}

/**
 * prend en argument une tête de liste et une valeur
 */
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

s_node* list_append(s_node* head, void* val){
    s_node* new_queue = (s_node*)malloc(sizeof(s_node));
    if(new_queue == NULL) return head;
    if(head != NULL){
        s_node* cur_queue = head;
        while(cur_queue->next!=NULL){
            cur_queue = cur_queue->next;
        }
        cur_queue->next = new_queue;
        list_set_data(new_queue, val);
        new_queue->next = NULL;
        return head;
    } else {
        list_set_data(new_queue, val);
        new_queue->next = NULL;
        return new_queue;
    }
}

s_node * list_orderedAppend(s_node ** head, int(*compare)(s_node *,void *), void * param){
    if(head == NULL){
        return list_insert(list_create(),param);
    }else if(*head == NULL){
        s_node * temp = list_insert(*head,param);
        *head = temp;
        return temp;
    }
    s_node * iteration = *head;
    //boucle
    while(iteration->next != NULL && compare(iteration->next,param)<0){ // on check le suivant pas l'iterateur directement
        iteration = iteration->next;
    }
    //debut des tests post boucle
    if(iteration->next != NULL){
        if(compare(iteration,param)==0){// iterateur == param et iterateur->next > param
            return iteration;
        }else if(compare(iteration,param)>0){// pas rentré dans la boucle iterateur != param et iterateur->next > param si ite>param alors insert et pas dans la boucle
            s_node * nv_head = list_insert(iteration,param);
            if(nv_head == iteration){
                return NULL;
            }
            *head = nv_head;
            return nv_head;
        }else if(compare(iteration,param)<0){// iterateur < param et iterateur->next > param
            s_node * nv_noeud = (s_node*) malloc(sizeof(s_node));
            if(nv_noeud == NULL){
                return NULL;
            }
            list_set_data(nv_noeud,param);
            nv_noeud->next = iteration->next;
            iteration->next = nv_noeud;
            return nv_noeud;
        }
    }// iterateur -> next == NULL donc append
    list_append(iteration, param);
    return iteration->next;
}

s_node * list_remove(s_node *head, void *data){
    if(head!=NULL){
        s_node * cur = head;
        s_node * prev = NULL;
        while(cur->val!=data && cur->next!=NULL){
            prev = cur;
            cur = cur->next;
        }
        if(cur->val==data){
            if(prev!=NULL){
                prev->next = cur->next;
            }
            else{
                head = cur->next;
            }
            free(cur);
            cur = NULL;
        }
    }
    return head;
}

s_node * list_headRemove(s_node * head){
    if(head == NULL){
        return NULL;
    }
    s_node * temp = head->next;
    free(head);
    head = NULL;
    return temp; 
}

void list_destroy(s_node *head){
    if(head!=NULL){
        s_node * cur = head;
        s_node * prev = NULL;
        while(cur->next!=NULL){
            prev = cur;
            cur = cur->next;
            free(prev);
            prev = NULL;
        }
        free(cur);
        cur = NULL;
        head = NULL;
    }
}

void display_list(s_node *head, void (*display)(s_node*)){
    if(head == NULL){
        return;
    }
    while(head->next != NULL){
        display(head);
        printf(" ");
        head = head->next;
    }
    display(head);
    printf("\n");
    return;
}

void display_int(s_node * noeud){
    printf("%d",(*(int*) noeud->val));
}

int comparer_int(s_node* node, void* data){
    if(list_get_data(node)!=NULL){
        int* val1 = (int*)list_get_data(node);
        int* val2 = (int*)data;
        return 1*(val1-val2);
    }
    return 2;
}