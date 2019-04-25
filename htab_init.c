#include "htab.h"
#include "htab_structures.h"

htab_t *htab_init(size_t n)
{
    htab_t *table;
    table = malloc(sizeof(htab_t) + (sizeof(struct htab_item)*n));
    if (table == NULL){
        fprintf(stderr, "Nepodarilo sa naalokovat potrebnu pamat!\n");
        return NULL;
    }

    table->arr_size = n;
    table->size = 0;

    int i = 0;
    while(i < table->arr_size){
        table->ptr[i++] = NULL;
    }

    return table;
}