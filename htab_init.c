#include "htab.h"
#include "htab_structures.h"

htab_t *htab_init(size_t n)
{
    htab_t *table;
    table = malloc(sizeof(struct htab) + (sizeof(struct htab_item)*n));
    if (table == NULL){
        fprintf(stderr, "Nepodarilo sa naalokovat potrebnu pamat!\n");
        return NULL;
    }

    table->arr_size = n;
    table->size = 0;

    return table;
}