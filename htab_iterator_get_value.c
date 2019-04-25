#include "htab.h"
#include "htab_structures.h"

int htab_iterator_get_value(htab_iterator_t it)
{
    return it.ptr->data;
}
