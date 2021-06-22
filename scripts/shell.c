#include <stdio.h>
#include "run.h"
#include "../src/utils/tuple/tuple.h"
#include "../src/utils/tokens-list/tokens-list.h"

void shell() {
  for(;;) {
    char text[4096];
    fgets(text, 4096, stdin);
    tuple lexerGeneratedTokensResult = run(text);

    if (lexerGeneratedTokensResult.b.strval != '\0') {
      printf("%s", lexerGeneratedTokensResult.b.strval);
    } else {
      printTokensList("%s", lexerGeneratedTokensResult.a.tlval);
    }
  }
}