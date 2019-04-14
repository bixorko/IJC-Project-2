#include "htab.h"
#include "htab_structures.h"

void htab_clear(htab_t * t)
{
    int i = 0;
    while(i < t->arr_size){
        t->ptr[i] = NULL;
        i++;
    }

    free(t);
}

