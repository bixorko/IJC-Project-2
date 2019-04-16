#include "htab.h"
#include "htab_structures.h"

htab_t *htab_move(size_t n, htab_t *from)
{
    int i = 0;
    struct htab_item *temp;
    htab_t *table;
    table = htab_init(n);
    size_t iterator = from->arr_size;

    while (i < iterator){
        temp = from->ptr[i];
        while(temp != NULL){
            table->ptr[i] = temp;
            temp = temp->next;
        }
        i++;
    }

    htab_clear(from);

    return table;
}