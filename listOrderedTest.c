s_node * list_orderedAppend(s_node ** head, int(*compare)(s_node *,void *), void * param){
    if(head!=NULL){
        if(*head!=NULL){
            s_node * cur = head;
            s_node * prev = NULL;
            while(compare(cur,param)<0 && cur->next != NULL){
                prev = cur;
                cur = cur->next;
            }
            if(compare(cur,param)==0){
                return cur;
            }
            if(compare(cur,param)>0){
                prev->next = list_insert(cur, param);
                return prev->next;
            }
            list_append(*head, param);
            return cur->next;
        }
        else{
            return list_append(*head, param);
        }
    }
    else{
        return list_insert(list_create(), param);
    }
}