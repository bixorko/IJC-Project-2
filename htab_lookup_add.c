#include "htab.h"

int error();

htab_iterator_t htab_lookup_add(htab_t * t, const char *key)
{
    size_t index = htab_hash_function(key) % t->arr_size;                           //index do tabulkky

    htab_iterator_t *temp = malloc(sizeof(htab_iterator_t));
    if (temp == NULL){
        error();
    }

    struct htab_item *item;                                                         //item pre iterovanie cez polozky
    item = t->ptr[index];

    while (item != NULL){
        if (!strcmp(item->key, key)){
            temp->t = t;
            temp->ptr = t->ptr[index];
            temp->ptr->key = key;
            temp->ptr->data++;
            temp->ptr->next = item->next;

            return *temp;
        }

        item = item->next;
    }

    item = malloc(sizeof(struct htab_item));

    item->key = malloc(strlen(key)+1);
    if (item->key == NULL){
        error();
    }

    item->key = key;
    item->next = NULL;
    item->data = 1;

    t->ptr[index] = item;

    temp->ptr = item;
    temp->t = t;
    temp->idx = (int)index;

    return *temp;
}

int error()
{
    fprintf(stderr, "Nepodarilo sa naalokovat potrebnu pamat!\n");
    return -1;
}