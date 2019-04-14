#include "htab.h"
#include "htab_structures.h"

htab_t *htab_init(size_t n)
{
    htab_t *t;
    t = malloc(sizeof(struct htab) + (sizeof(struct htab_item)*n));
    if (t == NULL){
        fprintf(stderr, "Nepodarilo sa naalokovat potrebnu pamat!\n");
        return NULL;
    }

    t->arr_size = n;

    return t;
}