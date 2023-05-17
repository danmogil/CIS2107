#include "ctype.h"
#include "strings.h"

int ends_with_ignore_case(char *s, char *suff) {
  unsigned int sLen = my_strlen(s);
  unsigned int suffLen = my_strlen(suff);

  if(suffLen <= sLen) {
    for(unsigned i = 1; i <= suffLen; i++) {
      if(tolower(s[sLen-i]) != tolower(suff[suffLen-i]))
        return 0;
    }
  }

  return 1;
}