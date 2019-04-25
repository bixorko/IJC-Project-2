#include "htab.h"
#include "htab_init.c"
#include "htab_free.c"
#include "htab_clear.c"
#include "htab_hash_function.c"
#include "htab_lookup_add.c"
#include "htab_end.c"
#include "htab_begin.c"
#include "htab_bucket_count.c"
#include "htab_iterator_get_key.c"
#include "htab_iterator_get_value.c"
#include "htab_iterator_set_value.c"
#include "htab_iterator_next.c"
#include "htab_size.c"
#include "io.c"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
        tab.ptr->data = (unsigned int)htab_iterator_set_value(tab,1);
        if (tab.ptr->key == NULL){
            htab_free(table);
            fclose(f);
            return -1;
        }
    }

    unsigned int i = 0;
    size_t iterator = htab_bucket_count(table);
    while (i < iterator){
        while (table->ptr[i] != NULL){
            tab.ptr = table->ptr[i];
            printf("%s\t%d\n", htab_iterator_get_key(tab), htab_iterator_get_value(tab));
            tab = htab_iterator_next(tab);
            table->ptr[i] = tab.ptr;
        }
        i++;
    }

    htab_free(table);
    fclose(f);
    return 0;
}