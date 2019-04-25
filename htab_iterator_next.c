#include "htab.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it)
{
    it.ptr->key = it.ptr->next->key;
    it.ptr->data = it.ptr->next->data;
    it.ptr->next = it.ptr->next->next;
    return it;
}
