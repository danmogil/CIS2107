#include "stdio.h"
#include "strings.h"

char *repeat(char *s, int x, char sep) {

  if(s == NULL) return NULL;
  
  int sLen = my_strlen(s);

  char *n[sLen*x + x-1];

  for(int i = 0; i < x;) {
    for(int j = 0; j < sLen; j++) {
      n[sLen * i + j] = s[j];
    }
    n[sLen * ++i] = sep;
  }

  return n;
}