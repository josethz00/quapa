//
// Created by jtsoa on 12/06/2021.
//
#include "../../utils/tuple/tuple.h"

struct Lexer {
    char text[100];
    int position;
    char currentChar;
};

void createLexer(struct Lexer * lexer, char value[]);
void advanceLexer(struct Lexer * lexer);
tuple makeTokensLexer(struct Lexer * lexer);
Token makeNumberLexer(struct Lexer * lexer);
