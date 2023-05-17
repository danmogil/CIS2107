#include <stdio.h>
#include <stdlib.h>

/*
Write a C program called revenue to calculate the revenue from a sale based on the unit price e
and quantity of a product input by the user. 
*/

int raise_error(char e[]);

int main(void) {

  float price;
  float quantity; // NOTE: This should be an unsigned int. However, this made it difficult to validate the user's input.
  float cost;
  float discount_rate; 

  // Print greeting
  puts("Welcome to the \"Temple\" store");

  // Get price
  printf("%s", "Enter item price: ");
  scanf("%f", &price);
  if(price < 0) raise_error("item price");

  // Get quantity
  printf("%s", "Enter quantity: ");
  scanf("%f", &quantity);
  if(quantity < 0 || (int) quantity != quantity) raise_error("quantity order");

  cost = price * quantity;

  // Set discount rate
  if(quantity < 50) discount_rate = 0;
  else if(quantity < 100) discount_rate = 0.1;
  else if(quantity < 150) discount_rate = 0.15;
  else discount_rate = 0.25;

  // Print results
  printf("The item price is: $%.2f\n", price);
  printf("The order is: %u item(s)\n", (int) quantity);
  printf("The cost is: $%.2f\n", cost);
  printf("The discount is: %u%%\n",(int) (discount_rate * 100));
  printf("The discount amount is: $%.2f\n", cost * discount_rate);
  printf("The total is: $%.2f\n", cost * (1 - discount_rate));

  // Print outro
  puts("Thank you for using \"Temple\" store");

  exit(1);
}

int raise_error(char e[]) {
  printf("This is not a valid %s.\nPlease run the program again", e);
  exit(0);
}