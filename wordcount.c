#include "htab.h"
#include "htab_init.c"
#include "htab_free.c"
#include "htab_clear.c"
#include "htab_hash_function.c"
#include "htab_lookup_add.c"
#include "htab_bucket_count.c"
#include "htab_iterator_next.c"
#include "htab_size.c"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "io.c"

int main(int argc, char **argv)
{
    if (argc != 2){
        fprintf(stderr, "Zle zadany pocet argumentov!\n");
        return -1;
    }

    char s[128];
    htab_t *table = htab_init(10000);
    htab_iterator_t tab;

    FILE *f;
    f = fopen(argv[1], "r");

    if (f == NULL){
        fprintf(stderr, "Nepodarilo sa otvorit subor\n");
        htab_free(table);
        return -1;
    }

    while(get_word(s,128,f) != EOF){
        tab = htab_lookup_add(table, s);
        if (tab.ptr->key == NULL){
            htab_free(table);
            fclose(f);
            return -1;
        }
    }

    unsigned int i = 0;
    while (i < table->arr_size){
        while (table->ptr[i] != NULL){
            printf("%s\t%d\n", table->ptr[i]->key, table->ptr[i]->data);
            table->ptr[i] = table->ptr[i]->next;
        }
        i++;
    }

    htab_free(table);
    fclose(f);
    return 0;
}