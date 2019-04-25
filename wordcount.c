#include "htab.h"
#include "htab_init.c"
#include "htab_free.c"
#include "htab_clear.c"
#include "htab_hash_function.c"
#include "htab_lookup_add.c"
#include "htab_bucket_count.c"
#include "htab_size.c"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "io.c"

int main(int argc, char **argv)
{
    char s[128];
    htab_t *table = htab_init(10000);
    htab_iterator_t tab;
    /*const char *key = "jozko";
    htab_iterator_t tab = htab_lookup_add(table, key);*/

    //printf("%d\n", tab.ptr->data);

    /*htab_iterator_t tab2 = htab_lookup_add(table, key);
    htab_iterator_t tab3 = htab_lookup_add(table, "jozko");
    htab_iterator_t tab4 = htab_lookup_add(table, "demetiatsgitastas");
    printf("%s\n", tab.ptr->key);
    printf("%s\n", tab4.ptr->key);
    printf("%d\n", tab.ptr->data);
    printf("%d\n", tab4.ptr->data);*/

    FILE *f;
    f = fopen(argv[1], "r");

    while(get_word(s,f) != EOF){
        tab = htab_lookup_add(table, s);
        //printf("%s    %d\n", tab.ptr->key, tab.ptr->data);
    }

   // printf("%s", table->ptr[4]->key);


    int i = 0;
    int j = 0;
    while (i < table->arr_size){
        while (table->ptr[i] != NULL){
            printf("%d:   %s    %d\n",i, table->ptr[i]->key, table->ptr[i]->data);
            table->ptr[i] = table->ptr[i]->next;
        }
        i++;
    }

    unsigned long retard = htab_bucket_count(table);
    unsigned long debil = htab_size(table);

    htab_free(table);
    return 0;
}