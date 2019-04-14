#include "htab.h"
#include "htab_structures.h"

void htab_clear(htab_t * t)
{
    int i = 0;

    struct htab_item *toDelete;
    struct htab_item *temp;
    size_t iterator = t->arr_size;

    while(i < iterator){

        toDelete = t->ptr[i];
        while(toDelete != NULL){
            temp = toDelete->next;
            free(toDelete);
            toDelete = temp;
        }

        i++;
    }

    free(t);
}

