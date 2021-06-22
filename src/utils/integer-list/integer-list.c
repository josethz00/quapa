//
// Created by jtsoa on 14/06/2021.
//

# include "integer-list.h"
#include <stdlib.h>

void initIntegerList(IntegerList *l) {
    size_t initialSize = 10;
    l->list = malloc(initialSize * sizeof(int));
    l->used = 0;
    l->size = initialSize;
}

void appendIntegerList(IntegerList *l, int element) {
    if (l->used == l->size) {
        l->size *= 2;
        l->list = realloc(l->list, l->size * sizeof(int));
    }
    l->list[l->used++] = element;
}

void freeIntegerList(IntegerList *l) {
    free(l->list);
    l->list = NULL;
    l->used = l->size = 0;
}