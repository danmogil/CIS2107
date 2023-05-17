#include "strings.h"

int num_in_range(char *s1, char b, char t) {
  int count = 0;

  int len = my_strlen(s1);

  for(unsigned int i = 0; i < len; i++) {
    if(b <= s1[i] && s1[i] <= t)
      count++;
  }

  return count;
}
