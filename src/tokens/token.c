//
// Created by jtsoa on 12/06/2021.
//
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createToken(Token * token, char type[], char value[]) {
    strcpy(token->type, type);
    strcpy(token->value, value);
}

char * reprToken(Token token) {
    const int typeFieldSize = sizeof(token.type);
    const int valueFieldSize = sizeof(token.value);
    const int totalStructSize = typeFieldSize + valueFieldSize;
    char * returnValue = (char*)malloc(totalStructSize * sizeof(char));
    if (strlen(token.value) == 0) {
        sprintf(returnValue, "%s:%s", token.type, token.value);
        return returnValue;
    }
    sprintf(returnValue, "%s:%s", token.type, token.value);
    return returnValue;
}