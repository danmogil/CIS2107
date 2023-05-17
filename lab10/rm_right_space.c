#include "strings.h"

void rm_right_space(char *s) {
  unsigned int len = my_strlen(s);
  unsigned int count = 0;

  while(s[len-count-1] == " ")
    count++;

  s[len-count] = "\0";  
}