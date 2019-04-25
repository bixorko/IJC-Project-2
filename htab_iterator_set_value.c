///////////////////////////////////////////////////////////////////////////
///                                IJC DU2                              ///
///                        htab_iterator_set_value.c                    ///
///                              VUT FIT BRNO                           ///
///                               12.4.2019                             ///
///                        xvinar00@stud.fit.vutbr.cz                   ///
///                             Peter Vinarcik                          ///
///////////////////////////////////////////////////////////////////////////

#include "htab.h"
#include "htab_structures.h"

int htab_iterator_set_value(htab_iterator_t it, int val)
{
    it.ptr->data += val;
    return it.ptr->data;
}