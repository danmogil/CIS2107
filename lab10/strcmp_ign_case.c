#include "strings.h"
#include <ctype.h>

int strcmp_ign_case(char *s1, char *s2) {
  tolower(s1);
  tolower(s2);

  if(s1 == s2) return 0;
  else if(s1 > s2) return 1;
  else return -1;
}