//
// Created by jtsoa on 14/06/2021.
//

#ifndef COMPILER_STRING_LIST_H
#define COMPILER_STRING_LIST_H

#endif //COMPILER_STRING_LIST_H

typedef struct {
    char ** list;
    size_t used;
    size_t size;
} StringList;

void initStringList(StringList *l);
void appendStringList(StringList *l, char element[]);
void freeStringList(StringList *l);