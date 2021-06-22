//
// Created by jtsoa on 14/06/2021.
//

#ifndef COMPILER_STRING_LIST_H
#define COMPILER_STRING_LIST_H

#endif //COMPILER_STRING_LIST_H

typedef struct {
    char * list;
    size_t used;
    size_t size;
} CharList;

void initCharList(CharList *l);
void appendCharList(CharList *l, char element);
void freeCharList(CharList *l);