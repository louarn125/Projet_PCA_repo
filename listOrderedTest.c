s_node * list_orderedAppend(s_node ** head, int(*compare)(s_node *,void *), void * param){
    if(head!=NULL){
        if(*head!=NULL){
            s_node * cur = head;
            s_node * prev = NULL;
            while(compare(cur->val,param)<0 && cur->next != NULL){
                prev = cur;
                cur = cur->next;
            }
            if(compare(cur->val,param)==0){
                return cur;
            }
            if(compare(cur->val,param)>0){
                s_node * new_node = list_insert(cur,param);
                if(new_node==cur){
                    return NULL;
                }
                if(prev!=NULL){
                    prev->next = new_node;
                    return prev->next;
                }
                else{
                    *head = new_node;
                    return *head;
                }
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