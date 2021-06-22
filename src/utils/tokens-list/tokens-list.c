//
// Created by jtsoa on 14/06/2021.
//

#include "tokens-list.h"

void initTokensList(TokensList *l) {
    size_t initialSize = 10;
    l->list = (Token*)malloc(initialSize * sizeof(Token));
    l->used = 0;
    l->size = initialSize;
}

void appendTokensList(TokensList *l, Token element) {
    if (l->used == l->size) {
        l->size += 1;
        l->list = realloc(l->list, l->size * sizeof(Token));
    }
    l->list[l->used++] = element;
}

void freeTokensList(TokensList *l) {
    free(l->list);
    l->list = NULL;
    l->used = l->size = 0;
}

void printTokensList(TokensList l, size_t tokensListLen) {
    size_t listIndex;
    for (listIndex = 0; listIndex < tokensListLen; listIndex++) {
        printf("%s\n", reprToken(l.list[listIndex]));
    }
}