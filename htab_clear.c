#include "htab.h"
#include "htab_structures.h"

void htab_clear(htab_t * t)
{
    unsigned int i = 0;

    while (i < t->arr_size){
        struct htab_item *next = NULL;
        while (t->ptr[i] != NULL){
            next = t->ptr[i]->next;
            free((char*)t->ptr[i]->key);
            free(t->ptr[i]);
            t->ptr[i] = next;
        }

        i++;
    }
}

