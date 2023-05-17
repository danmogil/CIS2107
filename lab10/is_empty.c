#include "strings.h"

int is_empty(char *s) {
  int len = my_strlen(s);
  
  if(s) {
    for(unsigned int i = 0; i < len; i++) {
      if(s[i] != ' ' && s[i] != '/0')
        return 0;
    }
  } 
  
  return 1;
}