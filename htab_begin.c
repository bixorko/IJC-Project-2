///////////////////////////////////////////////////////////////////////////
///                                IJC DU2                              ///
///                              htab_begin.c                           ///
///                              VUT FIT BRNO                           ///
///                               12.4.2019                             ///
///                        xvinar00@stud.fit.vutbr.cz                   ///
///                             Peter Vinarcik                          ///
///////////////////////////////////////////////////////////////////////////

#include "htab.h"
#include "htab_structures.h"

htab_iterator_t htab_begin(const htab_t * t)
{
    htab_iterator_t *temp = malloc(sizeof(htab_iterator_t));
    temp->t = t;
    temp->ptr=t->ptr[0];
    temp->idx = 0;

    return *temp;
}