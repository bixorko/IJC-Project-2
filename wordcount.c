#include "htab.h"
#include "htab_init.c"
#include "htab_free.c"
#include "htab_clear.c"
#include "htab_hash_function.c"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *fileLoad(char *file, int *count);

int main(int argc, char **argv)
{
    htab_t *table = htab_init(5);



    htab_free(table);
    return 0;
}

char *fileLoad(char *file, int *count)
{
    int counter = 0;
    int warning = 0;
    int lineBreak = 0;
    int c;
    size_t n = 0;
    size_t max = 1024;
    char *text = malloc(sizeof(text) * max);

    if (text == NULL){
        fprintf(stderr, "Nepodarilo sa naalokovat potrebnu pamat\n");
        return NULL;
    }

    FILE *pFile;
    pFile = fopen(file,"r");

    if (pFile == NULL){
        fprintf(stderr, "Nepodarilo sa otvorit subor\n");
        return NULL;
    }

    while ((c = fgetc(pFile)) != EOF){
        if (lineBreak == 1024 && c != '\n'){
            warning += 1;
            if (warning == 1){
                fprintf(stderr,"Riadok je dlhsi ako 1023 znakov, zvysna cast bude ignorovana\n");
            }
            text[n] = '\n';
            while((c = fgetc(pFile)) != '\n'){

            }
            lineBreak = 0;
        }

        text[n] = c;

        if (c == '\n'){
            counter++;
            lineBreak = 0;
        }
        if (n == max) {
            max += max;
            text = realloc(text, max*sizeof(char*));
            if (text == NULL){
                fprintf(stderr, "Nepodarilo sa realokovat pamat\n");
                return NULL;
            }
        }
        n++;
        lineBreak++;
    }
    text[n] = 0;
    *count = counter;

    fclose(pFile);
    return text;
}
