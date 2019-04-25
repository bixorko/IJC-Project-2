///////////////////////////////////////////////////////////////////////////
///                                IJC DU2                              ///
///                              htab_free.c                            ///
///                              VUT FIT BRNO                           ///
///                               12.4.2019                             ///
///                        xvinar00@stud.fit.vutbr.cz                   ///
///                             Peter Vinarcik                          ///
///////////////////////////////////////////////////////////////////////////

#include "htab.h"

void htab_free(htab_t * t)
{
    htab_clear(t);
    free(t);
}