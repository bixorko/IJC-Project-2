#include "htab.h"
#include "htab_structures.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it)
{
    it.ptr = it.ptr->next;
    return it;
}
