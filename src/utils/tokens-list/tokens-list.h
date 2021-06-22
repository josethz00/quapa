//
// Created by jtsoa on 14/06/2021.
//

#ifndef COMPILER_STRING_LIST_H
#define COMPILER_STRING_LIST_H

#endif //COMPILER_STRING_LIST_H

#include <stdlib.h>
#include "../../tokens/token.h"

typedef struct {
    Token * list;
    size_t used;
    size_t size;
} TokensList;

void initTokensList(TokensList *l);
void appendTokensList(TokensList *l, Token element);
void freeTokensList(TokensList *l);
void printTokensList(TokensList *l);