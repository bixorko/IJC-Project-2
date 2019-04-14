#include "htab.h"

void htab_free(htab_t * t)
{
    htab_clear(t);
}