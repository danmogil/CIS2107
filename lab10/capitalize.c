#include <stdio.h>
#include <ctype.h>
#include "strings.h"

void capitalize(char *s) {
  int len = my_strlen(s);

  for(unsigned int i = 0; i < len; i++) {
    s[i] = (i == 0 || (i > 0 && s[i-1] == " ")) ? toupper(s[i]) : tolower(s[i]);
  }
}