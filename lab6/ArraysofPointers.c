#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
  Daniel Mogil
  03/06/2023
  CIS2107
  Lab 6
  Design and implement array of function pointer
*/

void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);
int showMenu();

int main()
{
  void (*processGrades[4])(int students, int exams, int grades[students][exams]) = {printArray, minimum, maximum, average};
  
  unsigned int students, exams;
  printf("Enter the number of students: ");
  scanf("%u", &students);
  printf("Enter the number of exams: ");
  scanf("%u", &exams);


  int grades[students][exams];
  for(unsigned int i = 0; i < students; i++) {
    for(unsigned int j = 0; j < exams; j++) {
      printf("Enter student[%u]'s grade[%u]: ", i, j);
      scanf("%u", &grades[i][j]);
    }
  }

  unsigned int selected;
  do {
    selected = showMenu();
    (*processGrades[selected])(students, exams, grades);
  } while(selected != 4);
    
  exit(0);
}

void printArray(int students, int exams, int grades[students][exams]){
  printf("%s", "The grades are:");
  for(unsigned int i = 0; i < students; i++) {
    printf("\n\tStudent %u: ", i);
    for(unsigned int j = 0; j < exams; j++) {
      printf("%d ", grades[i][j]);
    }
  }
  puts("");
}

void minimum(int students, int exams, int grades[students][exams]){
  unsigned int min = UINT_MAX;

  for(unsigned int i = 0; i < students; i++) {
    for(unsigned int j = 0; j < exams; j++) {
      if(grades[i][j] < min) 
        min = grades[i][j];
    }
  }

  printf("The minimum is: %u\n", min);
}

void maximum(int students, int exams, int grades[students][exams]){
  unsigned int max = 0;

  for(unsigned int i = 0; i < students; i++) {
    for(unsigned int j = 0; j < exams; j++) {
      if(grades[i][j] > max) 
        max = grades[i][j];
    }
  }

  printf("The maximum is: %u\n", max);
}

void average(int students, int exams, int grades[students][exams]){
   for(unsigned int i = 0; i < students; i++) {

    unsigned int average = 0;
    
    for(unsigned int j = 0; j < exams; j++) {
      average += grades[i][j];
    }

    average /= exams;
    printf("Student %u's average is: %u\n", i, average);
  }
}

int showMenu() {
  unsigned int selected = UINT_MAX;
  
  while(selected > 4) {
    puts("\nEnter a choice:");
    puts("\t0 Print the array of grades");
    puts("\t1 Find the minimum grade");
    puts("\t2 Find the minimum grade");
    puts("\t3 Print the average on all tests for each student");
    puts("\t4 End Program");

    scanf("%u", &selected);
  }

  puts("");

  return selected;
}