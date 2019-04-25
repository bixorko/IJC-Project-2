///////////////////////////////////////////////////////////////////////////
///                                IJC DU2                              ///
///                             htab_lookup_add.c                       ///
///                              VUT FIT BRNO                           ///
///                               12.4.2019                             ///
///                        xvinar00@stud.fit.vutbr.cz                   ///
///                             Peter Vinarcik                          ///
///////////////////////////////////////////////////////////////////////////

#include "htab.h"
#include "htab_structures.h"

void errormsg();

htab_iterator_t htab_lookup_add(htab_t * t, const char *key)
{
    size_t index = htab_hash_function(key) % t->arr_size;                           //index do tabulkky

    htab_iterator_t temp = {0};

    struct htab_item *item;                                                         //item pre iterovanie cez polozky
    item = t->ptr[index];

    while (item != NULL){
        if (!strcmp(item->key, key)){
            temp.t = t;
            temp.ptr = t->ptr[index];
            strcpy((char*)temp.ptr->key, (char*)key);
            temp.ptr->next = item->next;

            return temp;
        }

        item = item->next;
    }

    item = malloc(sizeof(struct htab_item));
    if (item == NULL){
        errormsg();
        return temp;
    }

    item->key = malloc(strlen(key)+1);
    if (item->key == NULL){
        return temp;
    }

    strcpy((char*)item->key, (char*)key);
    item->next = NULL;

    t->ptr[index] = item;

    temp.ptr = item;
    temp.t = t;
    temp.idx = (int)index;

    //free(item->key);
    //free(item);

    return temp;
}

void errormsg()
{
    fprintf(stderr, "Nepodarilo sa naalokovat potrebnu pamat!\n");
}