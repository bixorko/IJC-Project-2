#include "htab.h"
//#include "htab_structures.h"

void htab_clear(htab_t * t)
{
    int i = 0;

    htab_t *table = t;

    struct htab_item *toDelete;
    struct htab_item *temp;
    size_t iterator = table->arr_size;

    while(i < iterator){

        toDelete = table->ptr[i];
        while(toDelete){
            temp = toDelete->next;
            free(toDelete);
            toDelete = temp;
        }
        (table->arr_size)--;
        i++;
    }
}

