///////////////////////////////////////////////////////////////////////////
///                                IJC DU2                              ///
///                                 tail.c                              ///
///                              VUT FIT BRNO                           ///
///                               12.4.2019                             ///
///                        xvinar00@stud.fit.vutbr.cz                   ///
///                             Peter Vinarcik                          ///
///////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *fileLoad(char *file, int *count);
char *stdinLoad(int *count);
int argumentsOne();
int argumentsTwo(char *argv[]);
int argumentsThree(char *argv[]);
int argumentsFour(char *argv[]);
void printDefaultN(char *argv[], char *text, int counter);
void printWithPlus(char *argv[], char *text, int counter);
void printDefaultTail(char *text, int counter);

int main(int argc, char *argv[])
{
    ///////////////////////////////////////////////////////////////////////////
    ///                              ONLY STDIN                             ///
    ///////////////////////////////////////////////////////////////////////////

    if (argc == 1){
        argumentsOne();
    }

    ///////////////////////////////////////////////////////////////////////////
    ///                             1 ARGUMENT                              ///
    ///////////////////////////////////////////////////////////////////////////

    else if (argc == 2){
        argumentsTwo(argv);
    }

    ///////////////////////////////////////////////////////////////////////////
    ///                             2 ARGUMENTY                             ///
    /// ///////////////////////////////////////////////////////////////////////

    else if (argc == 3){
        argumentsThree(argv);
    }

    ///////////////////////////////////////////////////////////////////////////
    ///                             3 ARGUMENTY                             ///
    ///////////////////////////////////////////////////////////////////////////

    else if (argc == 4){
        argumentsFour(argv);
    }

    ///////////////////////////////////////////////////////////////////////////
    ///                         ZLY POCET ARGUMENTOV                        ///
    ///////////////////////////////////////////////////////////////////////////

    else{
        fprintf(stderr, "Zle zadany pocet argumentov\n");
        return -1;
    }

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

char *stdinLoad(int *count)
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

    while ((c = getchar()) != EOF){
        if (lineBreak == 1024 && c != '\n'){
            warning += 1;
            if (warning == 1){
                fprintf(stderr,"Riadok je dlhsi ako 1023 znakov, zvysna cast bude ignorovana\n");
            }
            text[n] = '\n';
            while((c = getchar()) != '\n'){

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

    return text;
}

int argumentsOne()
{
    char *text;
    int counter;

    ///LOAD ZO STDIN
    text = stdinLoad(&counter);

    printDefaultTail(text, counter);

    return 0;
}

int argumentsTwo(char *argv[])
{
    char *text;
    int counter;

    ///LOAD ZO SUBORU
    char *FileName = argv[1];
    text = fileLoad(FileName, &counter);
    if (text == NULL) {
        return -1;
    }

    printDefaultTail(text, counter);

    return 0;
}

int argumentsThree(char *argv[])
{
    int counter;
    char *text;

    text = stdinLoad(&counter);

    if (argv[2][0] == '+') {
        printWithPlus(argv, text, counter);
    }
    else {
        printDefaultN(argv, text, counter);
    }

    return 0;
}

int argumentsFour(char *argv[])
{
    int counter;
    char *text;

    if (strcmp(argv[1],"-n") != 0 || !(strtol(argv[2], NULL, 10))) {
        fprintf(stderr, "Zle zadane argumenty\n");
        return -1;
    }

    char *FileName = argv[3];
    text = fileLoad(FileName, &counter);
    if (text == NULL){
        return -1;
    }

    if (argv[2][0] == '+') {
        printWithPlus(argv, text, counter);
    }
    else {
        printDefaultN(argv, text, counter);
    }

    return 0;
}

void printDefaultN(char *argv[], char *text, int counter)
{
    ///VYPISAT UPRAVENY SUBOR KLASICKY TAIL ALEBO '-'
    int pom = (int) strtol(argv[2], NULL, 10);
    pom = abs(pom);
    int i = 0;
    int toLast = 0;
    int x = counter-pom;

    ///PRESKOCI AZ NA POSLEDNYCH 10 RIADKOV
    while(toLast != x) {
        while (text[i] != '\n') {

            i++;
        }
        i++;
        toLast++;
    }

    ///VYPISE POSLEDNYCH 10 RIADKOV
    while(toLast != counter){
        while (text[i] != '\n') {
            printf("%c", text[i]);
            i++;
        }
        printf("\n");
        i++;
        toLast++;
    }
    free(text);
}

void printWithPlus(char *argv[], char *text, int counter)
{
    ///VYPISAT UPRAVENY SUBOR s '+'
    int pom = (int) strtol(argv[2], NULL, 10);
    if (pom < 0){
        pom *= (-1);
    }
    int i = 0;
    int toLast = 0;

    ///PRESKOCI AZ NA POSLEDNYCH 10 RIADKOV
    while(toLast < pom-1) {
        while (text[i] != '\n') {

            i++;
        }
        i++;
        toLast++;
    }
    while(toLast < counter){
        while (text[i] != '\n') {
            printf("%c", text[i]);
            i++;
        }
        printf("\n");
        i++;
        toLast++;
    }
    free(text);
}

void printDefaultTail(char *text, int counter)
{
    int i = 0;
    int toLast = 0;
    int x = counter - 10;

    ///PRESKOCI AZ NA POSLEDNYCH 10 RIADKOV
    while (toLast != x) {
        while (text[i] != '\n') {

            i++;
        }
        i++;
        toLast++;
    }

    ///VYPISE POSLEDNYCH 10 RIADKOV
    while (toLast != counter) {
        while (text[i] != '\n') {
            printf("%c", text[i]);
            i++;
        }
        printf("\n");
        i++;
        toLast++;
    }
    free(text);
}