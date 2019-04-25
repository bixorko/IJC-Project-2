///////////////////////////////////////////////////////////////////////////
///                                IJC DU2                              ///
///                               wordcount.c                           ///
///                              VUT FIT BRNO                           ///
///                               12.4.2019                             ///
///                        xvinar00@stud.fit.vutbr.cz                   ///
///                             Peter Vinarcik                          ///
///////////////////////////////////////////////////////////////////////////

#include "htab.h"
#include "io.c"
#include "htab_structures.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[128];

    /**
        kedze dopredu nevieme velkost suboru, resp kolko slov sa bude nachadzat v zadanom texte, musime len odhadnut velkost
        na: http://cseweb.ucsd.edu/~kube/cls/100/Lectures/lec16/lec16-8.html som nasiel, ze udajne by sme sa mali riadit pravidlom
        ze dlzka ma byt 1.3x vacsia ako pocet klucov, ktore budu v tabulke a dalej by mala byt velkost hashovacej tabulky prvocislo
        tak som zvolil 10007 co mi pride dostatocna velkost na danu ulohu
    **/

    htab_t *table = htab_init(10007);
    htab_iterator_t tab;

    ///////////////////////////////////////////////////////////////////////////
    ///                              ONLY STDIN                             ///
    ///////////////////////////////////////////////////////////////////////////

    while (get_word(s, 127, stdin) != EOF) {
        tab = htab_lookup_add(table, s);
        tab.ptr->data = (unsigned int) htab_iterator_set_value(tab, 1);
        if (tab.ptr->key == NULL) {
            htab_free(table);
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

    htab_free(table);;
    return 0;
}
