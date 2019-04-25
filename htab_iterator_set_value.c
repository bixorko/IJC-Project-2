#include "htab.h"

int htab_iterator_set_value(htab_iterator_t it, int val)
{
    it.ptr->data += val;
    return it.ptr->data;
}