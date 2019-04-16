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

    struct htab_item *item = malloc(sizeof(struct htab_item));
    item->key = "dememnt";
    table->ptr[0] = item;
    printf("%s", table->ptr[0]->key);

    printf("%d\n", (int)table->arr_size);

    return table;
}