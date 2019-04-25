#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int get_word(char *s, FILE *f)
{
    int counter = 0;
    int warning = 0;
    int lineBreak = 0;
    int c;
    size_t n = 0;


    if (f == NULL){
        fprintf(stderr, "Nepodarilo sa otvorit subor\n");
        return -1;
    }

    while ((c = fgetc(f)) != EOF){
        if (isspace(c)){
            s[n] = '\0';
            break;
        }
        s[n] = c;
        n++;
        counter++;
    }

    if (c == EOF){
        return EOF;
    }

    return counter;
}