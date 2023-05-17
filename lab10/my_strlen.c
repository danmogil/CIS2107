#include "strings.h"

int my_strlen(char *s) {
  char *t=s;
  while (*t!='\0')
    t++;
  return t-s;
}
