#include "htab.h"

struct htab_item{
    char *key;
    unsigned int data;
    struct htab_item *next;
};

struct htab{
    size_t size;
    size_t arr_size;
    struct htab_item *ptr[];
};