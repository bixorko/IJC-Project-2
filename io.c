///////////////////////////////////////////////////////////////////////////
///                                IJC DU2                              ///
///                                  io.c                               ///
///                              VUT FIT BRNO                           ///
///                               12.4.2019                             ///
///                        xvinar00@stud.fit.vutbr.cz                   ///
///                             Peter Vinarcik                          ///
///////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int get_word(char *s, int max, FILE *f)
{
    int counter = 0;
    int lineBreak = 0;
    int c;
    size_t n = 0;

    while ((c = fgetc(f)) != EOF){
        if (lineBreak == max && !isspace(c)){
            s[n] = '\0';
            while (!isspace(c)){
                c = fgetc(f);
            }
            break;
        }

        if (isspace(c)){
            s[n] = '\0';
            break;
        }

        s[n] = c;
        n++;
        lineBreak++;
        counter++;
    }

    if (c == EOF){
        return EOF;
    }

    return counter;
}