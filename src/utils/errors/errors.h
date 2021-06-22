typedef struct {
  char errorName[30];
  char details[100];
} Error;

char * createError(Error * error, char errorName[], char details[]);
char * reprAsStringError(Error error);