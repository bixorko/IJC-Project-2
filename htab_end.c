#include "htab.h"

htab_iterator_t htab_end(const htab_t * t)
{
    htab_iterator_t *temp = malloc(sizeof(htab_iterator_t));
    temp->t = t;
    struct htab_item *iter;
    iter = t->ptr[(t->arr_size)-1];

    while(iter != NULL){
        iter = iter->next;
    }

    temp->t = t;
    temp->ptr->key = iter->key;
    temp->ptr->data = iter->data;
    temp->ptr->next = iter->next;
    temp->idx = (int)(t->arr_size)-1;

    return *temp;
}
