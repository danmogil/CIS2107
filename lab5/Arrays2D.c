#include <stdio.h>
#include <limits.h>

/*
  Daniel Mogil
  02/25/23
  CIS2107
  Lab 5
  Design and implement functions to process 2DArrays.
  NO NEED FOR INPUT VALIDATION
*/

static unsigned int rows;
static unsigned int cols;

int max(int arr[rows][cols]);
int rowSum(int arr[rows][cols], unsigned int x);
int columnSum(int arr[rows][cols], unsigned int x);
unsigned int isSquare(int arr[rows][cols]);
void displayOutputs(int arr[rows][cols]);

int main(void) {
  puts("Let's create a 2Dim array!\n\n");

  printf("\tHow many rows? ");  
  scanf("%u", &rows);

  printf("\tHow many columns? ");  
  scanf("%u", &cols);

  int arr[rows][cols];

  printf("\n");

  for(unsigned int i = 0; i < rows; i++) {
    for(unsigned int j = 0; j < cols; j++) {
      printf("\tEnter [%u][%u]: ", i, j);
      scanf("%d", &arr[i][j]);
    }
  }

  printf("\n");

  for(unsigned int i = 1; i <= rows; i++) {
    printf("Sum of row %u = %d\n", i, rowSum(arr, i-1));
  }

  printf("\n");

  for(unsigned int i = 1; i <= cols; i++) {
    printf("Sum of column %u = %d\n", i, columnSum(arr, i-1));
  }

  printf("\n");

  printf("This is%s a square array.\n\n", isSquare(arr) ? "" : " not");
  
  displayOutputs(arr);
}

int max(int arr[rows][cols]) {
  int max = INT_MIN;

  for(unsigned int i = 0; i < rows; i++) {
    for(unsigned int j = 0; j < cols; j++) {
      if(arr[i][j] > max) max = arr[i][j];
    }
  }

  return max;
}

int rowSum(int arr[rows][cols], unsigned int x) {
  int sum = 0;
  
  for(unsigned int i = 0; i < cols; i++) {
    sum += arr[x][i];
  }

  return sum;
}

int columnSum(int arr[rows][cols], unsigned int x) {
  int sum = 0;
  
  for(unsigned int i = 0; i < rows; i++) {
    sum += arr[i][x];
  }

  return sum;
}

unsigned int isSquare(int arr[rows][cols]) {
  return rows == cols;
}

void displayOutputs(int arr[rows][cols]) {
  puts("Here is your 2Dim array:");
  for(unsigned int i = 0; i < rows; i++) {

    for(unsigned int j = 0; j < cols; j++) {
      if(j == 0) printf("[");

      printf("%d", arr[i][j]);
      
      printf( (j == cols - 1) ? "]" : ", ");
    }

    printf("\n");
  }
}