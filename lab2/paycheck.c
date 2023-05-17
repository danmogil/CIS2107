#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Daniel Mogil
02/02/23
CIS2107
Lab 02
Write a C program called paycheck to calculate the paycheck for a Temple employee based on the hourlySalary, weeklyTime 
(working for maximum 40 hours) and overtime (working for more than 40 hours). 
*/

const float OVERTIME_RATE = 1.5;
const char DIVIDER[] = "==============================\n";

int raise_error(char e[]); 

int main(void) {

  float employee_num; // NOTE: This should be an unsigned int. However, this made it difficult to validate the user's input.
  float hourly_rate;
  float hours_worked;
  float regular_pay;
  float overtime_pay;

  // Print greeting
  puts("Welcome to \"TEMPLE HUMAN RESOURCES\"");

  // Get ID
  printf("%s", "Enter Employee Number: ");
  scanf("%f", &employee_num);
  if(employee_num < 0 || (int) employee_num != employee_num) raise_error("Employee Number");

  // Get pay rate
  printf("%s", "Enter Hourly Salary: ");
  scanf("%f", &hourly_rate);
  if(hourly_rate < 0) raise_error("hourly salary amount");

  // Get time worked
  printf("%s", "Enter Weekly Time: ");
  scanf("%f", &hours_worked);
  if(hours_worked < 0) raise_error("weekly time");

  printf("%s", &DIVIDER);

  // Calculate pay
  regular_pay = hourly_rate * hours_worked;
  overtime_pay = (hours_worked > 40) ? OVERTIME_RATE * hourly_rate * (hours_worked - 40) : 0;

  // Print results
  printf("Employee #: %u\n", (int) employee_num);
  printf("Hourly Salary: $%.2f\n", hourly_rate);
  printf("Weekly Time: %.2f\n", hours_worked);
  printf("Regular Pay: $%.2f\n", regular_pay);
  printf("Overtime Pay: $%.2f\n", overtime_pay);
  printf("Net Pay: $%.2f\n", regular_pay + overtime_pay);

  printf("%s", &DIVIDER);

  // Print outro
  puts("Thank you for using \"TEMPLE HUMAN RESOURCES\"");

  exit(1);
}

  int raise_error(char e[]) {
    printf("This is not a valid %s.\nPlease run the program again", e);
    exit(0);
  }