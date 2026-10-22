s_node * list_orderedAppend(s_node * head, compare, void * param){
    if(head!=NULL){
        s_node * cur = head;
        s_node * prev = NULL;
        while(cur<param && cur->next != NULL){
            prev = cur;
            cur = cur->next;
        }
        if(cur==param){
            return cur;
        }
        if(cur>param){
            prev->next = list_insert(cur, param);
            return head;
        }
        return list_append(head, param);
    }
    else{
        return list_append(head, param);
    }
}