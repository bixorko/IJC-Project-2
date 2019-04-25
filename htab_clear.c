#include "htab.h"

void htab_clear(htab_t * t)
{
    int i = 0;

    htab_t *table = t;

    struct htab_item *toDelete;
    struct htab_item *temp;
    toDelete = table->ptr[i];
    size_t iterator = table->arr_size;

    while(i < iterator){

        while(toDelete){
            temp = toDelete->next;
            toDelete = temp;
        }
        (table->arr_size)--;
        i++;
    }
}

