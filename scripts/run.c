#include "../src/core/lexer/lexer.h"

tuple run(char text[]) {
  struct Lexer lexer;
  createLexer(&lexer, text);

  tuple lexerGeneratedTokensResult = makeTokensLexer(&lexer);
  return lexerGeneratedTokensResult;
}