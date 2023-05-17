#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 40
#define ARR_RAND_MIN 0
#define ARR_RAND_MAX 100

/*
  Daniel Mogil
  02/19/23
  CIS2107
  Lab 4
  The goal is to design and implement functions to process 1D Arrays
*/

void fillArray(int arr[]);
int findWithRange(int arr[], int lowSelectedRange, int highSelectedRange);
void reverseArray(int arr[]);
void reverseSelectedRangeWithinArray(int arr[], int startRange, int endRange);
int findSequence(int arr[]);

void printArray(int arr[]);
void validateRange(int lowRange, int highRange);
void _reverseArray(int arr[], int l, int h);

int main(void) {

  srand((unsigned)time(NULL));
  int arr[SIZE];

  fillArray(arr);
  printArray(arr);

  printf("\n\n");

  unsigned int lowSelectedRange = 0;
  unsigned int highSeletedRange = 9;
  printf("Max within indices (%u-%u) = %d", lowSelectedRange, highSeletedRange, findWithRange(arr, lowSelectedRange, highSeletedRange));

  printf("\n\n");

  puts("Reversed:");
  reverseArray(arr);
  printArray(arr);

  printf("\n\n");

  unsigned int startRange = 0;
  unsigned int endRange = 9;
  printf("Reversing between indices (%u, %u):\n", startRange, endRange);
  reverseSelectedRangeWithinArray(arr, startRange, endRange);
  printArray(arr);

  printf("\n\n");

  int sequenceI = findSequence(arr);
  if(sequenceI == -1) puts("Sequence not found");
  else printf("Sequence found at index %d\n", sequenceI);

}

void fillArray(int arr[]) {
  for(unsigned int i = 0; i < SIZE; i++) {
    arr[i] = rand() % (ARR_RAND_MAX + 1)+ ARR_RAND_MIN;
  }
}

int findWithRange(int arr[], int lowSelectedRange, int highSelectedRange) {
  validateRange(lowSelectedRange, highSelectedRange);

  int max = (int) ARR_RAND_MIN - 1;
  for(unsigned int i = lowSelectedRange; i <= highSelectedRange; i++) {
    if(arr[i] > max) max = arr[i];
  }

  return max;
}

void reverseArray(int arr[]) {
  _reverseArray(arr, 0, SIZE - 1);
}

void reverseSelectedRangeWithinArray(int arr[], int startRange, int endRange) {
  _reverseArray(arr, startRange, endRange);
}

int findSequence(int arr[]) {
  int n1, n2;

  printf("Enter two numbers: ");
  scanf("%d %d", &n1, &n2);

  if((n1 >= ARR_RAND_MIN && n1 <= ARR_RAND_MAX) && (n2 >= ARR_RAND_MIN && n2 <= ARR_RAND_MAX)) {
    for(unsigned int i = 0; i < SIZE - 1; i++) {
        if(arr[i] == n1 && arr[i+1] == n2)
          return i;
    } 
  }

  return -1;
}

// Helpers
void printArray(int arr[]) {
  for(unsigned int i = 0; i < SIZE; i++) {
    if(i % 10 == 0 && i > 0)
      printf("\n");
    printf("%6d", arr[i]);
  }
}

void validateRange(int lowRange, int highRange) {
  if(lowRange < 0 || highRange < lowRange) {
      puts("Invalid range!");
      exit(0);
    }
}

void _reverseArray(int arr[], int l, int h) {
  validateRange(l, h);

  while(l < h) {
    int temp = arr[l];
    arr[l++] = arr[h];
    arr[h--] = temp;
  }
}