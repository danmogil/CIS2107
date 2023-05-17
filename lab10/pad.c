#include "stdio.h"
#include "strings.h"

char *pad(char *s, int d) {
  unsigned int len = my_strlen(s);

  if(s == NULL) return NULL;

  int size = len;

  while(size%d != 0 && size%2 != 0) size++;

  char *x[size];

  for(unsigned int i = 0; i < size; i++) {
    x[i] = i < len ? s[i] : " ";
  }

  return x;
}