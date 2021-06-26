//
// Created by jtsoa on 12/06/2021.
//
#include "lexer.h"
#include "../../utils/tokens-list/tokens-list.h"
#include "../../utils/char-list/char-list.h"
#include "../../tokens/token.h"
#include "../../../constants/tokens-constants.h"
#include "../../utils/errors/errors.h"
#include "../../utils/tuple/tuple.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void createLexer(struct Lexer * lexer, char text[]) {
    lexer->text = text;
    lexer->position = -1;
    advanceLexer(lexer);
}

void advanceLexer(struct Lexer * lexer) {
    const int textArrayLen = sizeof lexer->text / sizeof * lexer->text;
    lexer->position +=1;
    lexer->currentChar = (lexer->position < textArrayLen) ? lexer->text[lexer->position] : '\0' ;
}

tuple makeTokensLexer(struct Lexer * lexer) {
    TokensList tokens;
    initTokensList(&tokens);
    Token lToken;
    Error lexError;
    tuple lexTokensReturn;

    while (lexer->currentChar != '\0') {
        if (lexer->currentChar == ' ' || lexer->currentChar == '\t') {
            advanceLexer(&lexer);
        } else if (strchr(TT_DIGITS, lexer->currentChar) != NULL) {
            appendTokensList(&tokens, makeNumberLexer(&lexer));
        } else if (lexer->currentChar == '+') {
            createToken(&lToken, TT_PLUS, "+");
            appendTokensList(&tokens, lToken);
            advanceLexer(&lexer);
        } else if (lexer->currentChar == '-') {
            createToken(&lToken, TT_MINUS, "-");
            appendTokensList(&tokens, lToken);
            advanceLexer(&lexer);
        } else if (lexer->currentChar == '*') {
            createToken(&lToken, TT_MUL, "*");
            appendTokensList(&tokens, lToken);
            advanceLexer(&lexer);
        } else if (lexer->currentChar == '/') {
            createToken(&lToken, TT_DIV, "*");
            appendTokensList(&tokens, lToken);
            advanceLexer(&lexer);
        } else if (lexer->currentChar == '(') {
            createToken(&lToken, TT_LPAREN, "(");
            appendTokensList(&tokens, lToken);
            advanceLexer(&lexer);
        } else if (lexer->currentChar == ')') {
            createToken(&lToken, TT_RPAREN, ")");
            appendTokensList(&tokens, lToken);
            advanceLexer(&lexer);
        } else {
            const char errorMsg[] = "Error <Illegal Character>" ;
            size_t errorMsgLen = sizeof(errorMsg) / sizeof(* errorMsg);
            char * stringError = (char *)malloc(errorMsgLen * sizeof(char) + 1 + 1);

            sprintf(stringError, "%s <%c>", errorMsg, lexer->currentChar);
            createError(&lexError, stringError, "No details for this error");
            lexTokensReturn.b.strval = reprAsStringError(error);
            return lexTokensReturn;
        }
    }
    lexTokensReturn.a.tlval = tokens;
    return lexTokensReturn;
}

Token makeNumberLexer(struct Lexer * lexer) {
    CharList numberString;
    unsigned int dotCount = 0;
    size_t ttDigitsLen = strlen(TT_DIGITS);
    Token numericToken;

    char * TT_DIGITS_WITH_DOT = malloc(ttDigitsLen + 1 + 1);
    
    strcpy(TT_DIGITS_WITH_DOT, TT_DIGITS);
    TT_DIGITS_WITH_DOT[ttDigitsLen] = '.';
    TT_DIGITS_WITH_DOT[ttDigitsLen + 1] = '\0';

    initCharList(&numberString);

    while (lexer->currentChar != '\0' && 
        strchr(TT_DIGITS_WITH_DOT, lexer->currentChar) != NULL
    ) {
        if (lexer->currentChar == '.') {
            if (dotCount == 1) {
                break;
            }
            dotCount +=1;
            appendCharList(&numberString, lexer->currentChar);
        } else {
            appendCharList(&numberString, lexer->currentChar);
        }
        advanceLexer(&lexer);
    }
    if (dotCount == 0) {
        createToken(&numericToken, TT_INT, numberString.list);
        return numericToken;
    }
    createToken(&numericToken, TT_INT, numberString.list);
    return numericToken;
}
