#include "errors.h"

void createError(Error * error, char errorName[], char details[]) {
  strcpy(error->errorName, errorName);
  strcpy(error->details, details);
}

char * reprAsStringError(Error error) {
  const int totalStructSize = sizeof(Error);
  char * returnValue = (char*)malloc(totalStructSize * sizeof(char));
  sprintf(returnValue, "%s: %s", error.errorName, error.details);
  return returnValue;
}