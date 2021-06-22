//
// Created by jtsoa on 14/06/2021.
//

# include "char-list.h"
#include <stdlib.h>

void initCharList(CharList *l) {
    size_t initialSize = 10;
    l->list = malloc(initialSize * sizeof(char));
    l->used = 0;
    l->size = initialSize;
}

void appendCharList(CharList *l, char element) {
    if (l->used == l->size) {
        l->size += 1;
        l->list = realloc(l->list, l->size * sizeof(char *));
    }
    l->list[l->used++] = element;
}

void freeCharList(CharList *l) {
    free(l->list);
    l->list = NULL;
    l->used = l->size = 0;
}