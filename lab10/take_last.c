#include "strings.h"

void take_last(char *s, int n) {
  unsigned int len = my_strlen(s);
  
  if(n < len)
    s += len;
}