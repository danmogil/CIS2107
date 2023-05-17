#include <stdio.h>
#include <stdlib.h>

#include "strings.h"

int diff(char *s1, char *s2) {

  int s1Len = my_strlen(s1);
  int s2Len = my_strlen(s2);

  int count = abs(s1Len - s2Len);

  for(unsigned int i = 0; i < my_min(s1Len, s2Len); i++) {
    if(s1[i] != s2[i])
      count++;
  }

  return count;
}