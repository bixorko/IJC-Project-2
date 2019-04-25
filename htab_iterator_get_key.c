#include "htab.h"
#include "htab_structures.h"

const char * htab_iterator_get_key(htab_iterator_t it)
{
    return it.ptr->key;
}

