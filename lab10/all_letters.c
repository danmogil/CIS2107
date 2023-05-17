#include "strings.h"

int all_letters(char *s) {

  int len = my_strlen(s);

  for(unsigned int i = 0; i < len; i++) {
    if( (s[i] < 65 || s[i] > 90) && (s[i] < 97 || s[i] > 122) )
      return 0;
  }

  return 1;
}