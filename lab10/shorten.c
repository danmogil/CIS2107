#include "strings.h"

void shorten(char *s, int new_len) {
  if(my_strlen(s) <= new_len)
    return;
  
  s[new_len] = 0;
}
