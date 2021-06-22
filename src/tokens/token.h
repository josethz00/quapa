//
// Created by jtsoa on 12/06/2021.
//
typedef struct {
  char type[20];
  char value[100];
} Token;

void createToken(Token *token, char type[], char value[]);
char * reprToken(Token token);
char * makeNumberLexer(struct Lexer * lexer);