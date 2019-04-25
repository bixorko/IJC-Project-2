#include "htab.h"

void errormsg();

htab_iterator_t htab_lookup_add(htab_t * t, const char *key)
{
    size_t index = htab_hash_function(key) % t->arr_size;                           //index do tabulkky

    htab_iterator_t *temp = malloc(sizeof(htab_iterator_t));
    if (temp == NULL){
        errormsg();
        return *temp;
    }

    struct htab_item *item;                                                         //item pre iterovanie cez polozky
    item = t->ptr[index];

    while (item != NULL){
        if (!strcmp(item->key, key)){
            temp->t = t;
            temp->ptr = t->ptr[index];
            strcpy((char*)temp->ptr->key, (char*)key);
            temp->ptr->data++;
            temp->ptr->next = item->next;

            return *temp;
        }

        item = item->next;
    }

    item = malloc(sizeof(struct htab_item));
    if (item == NULL){
        errormsg();
        temp = NULL;
        return *temp;
    }

    item->key = malloc(strlen(key)+1);
    if (item->key == NULL){
        temp = NULL;
        return *temp;
    }

    strcpy((char*)item->key, (char*)key);
    item->next = NULL;
    item->data = 1;

    t->ptr[index] = item;

    temp->ptr = item;
    temp->t = t;
    temp->idx = (int)index;

    return *temp;
}

void errormsg()
{
    fprintf(stderr, "Nepodarilo sa naalokovat potrebnu pamat!\n");
}