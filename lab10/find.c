#include "strings.h"

int find(char *h, char *n) {
  int lenH = my_strlen(h);
  int lenN = my_strlen(n);

  for(unsigned int i = 0; i < lenH; i++) {
    for(unsigned int j = 0; j < lenN; j++) {
      if(h[i] == n[j])
        continue;
      goto cnt;
    }
    return i;
    cnt:;
  }

  return -1;
}