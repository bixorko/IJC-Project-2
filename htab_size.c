///////////////////////////////////////////////////////////////////////////
///                                IJC DU2                              ///
///                              htab_size.c                            ///
///                              VUT FIT BRNO                           ///
///                               12.4.2019                             ///
///                        xvinar00@stud.fit.vutbr.cz                   ///
///                             Peter Vinarcik                          ///
///////////////////////////////////////////////////////////////////////////

#include "htab.h"
#include "htab_structures.h"

size_t htab_size(const htab_t * t)
{
    return t->size;
}