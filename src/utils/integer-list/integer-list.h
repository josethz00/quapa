//
// Created by jtsoa on 14/06/2021.
//

#ifndef COMPILER_INTEGER_LIST_H
#define COMPILER_INTEGER_LIST_H

#endif //COMPILER_INTEGER_LIST_H

typedef struct {
    int * list;
    size_t used;
    size_t size;
} IntegerList;

void initIntegerList(IntegerList *l, size_t initialSize);
void appendIntegerList(IntegerList *l, int element);
void freeIntegerList(IntegerList *l);