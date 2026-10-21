s_node * list_orderedAppend(s_node * head, compare, void * param){
    s_node * cur = head;
    s_node * prev = NULL;
    while(cur<param && cur->next != NULL){
        prev = cur;
        cur = cur->next;
    }
    if(cur==param){
        return cur;
    }
    s_node* new_node = malloc...;
    if(cur>param){
        prev->next = new_node;
        new_node->next = cur;
        list_set_data(new_node, param);
        return head;
    }
    list.append(head, param);
    return head;
}