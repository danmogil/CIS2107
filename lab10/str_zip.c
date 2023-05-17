#include "strings.h"

char *str_zip(char *s1, char *s2) {
  int lenS1 = my_strlen(s1);
  int lenS2 = my_strlen(s2);

  char s[lenS1+lenS2];

  for(unsigned int i = 0; i < my_max(lenS1, lenS2); i++) {
    if(i < lenS1 && i < lenS2) {
      s[i] = s1[i++];
      s[i] = s2[i-1];
    }

    else s[i] = i < lenS1 ? s1[i] : s2[i];
  }
  
  return s;
}