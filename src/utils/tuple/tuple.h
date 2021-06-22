#include "../../utils/tokens-list/tokens-list.h"

typedef struct 
{
  union {
    int ival;
    float fval;
    char cval;
    char strval[200];
    TokensList tlval

  } a;
  union {
    int ival;
    float fval;
    char cval;
    char strval[200];
    TokensList tlval
  } b;
} tuple;