#include "htab.h"

htab_iterator_t htab_begin(const htab_t * t)
{
    htab_iterator_t *temp = malloc(sizeof(htab_iterator_t));
    temp->t = t;
    temp->ptr=t->ptr[0];
    temp->idx = 0;

    return *temp;
}