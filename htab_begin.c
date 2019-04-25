#include "htab.h"

htab_iterator_t htab_begin(const htab_t * t)
{
    htab_iterator_t *temp = malloc(sizeof(htab_iterator_t));
    temp->t = t;
    temp->ptr->key = t->ptr[0]->key;
    temp->ptr->data = t->ptr[0]->data;
    temp->ptr->next = t->ptr[0]->next;
    temp->idx = 0;

    return *temp;
}