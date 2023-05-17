#include "strings.h"

void rm_left_space(char *s) {
  unsigned int count = 0;

  while(s[count] == " ")
    count++;

  s += count;
}