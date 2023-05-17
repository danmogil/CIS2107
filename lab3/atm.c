#include <stdio.h>
#include <stdlib.h>

/*
  Daniel Mogil
  02/10/23
  Lab 3
  Write a C Program for an ATM machine by implementing functions.
*/

unsigned int balance = 5000;
unsigned int PIN = 3014;

unsigned int num_transactions = 0;
unsigned int deposit_limit_remaining = 10000;
unsigned int withdrawal_limit_remaining = 1000;

int main(void) {

  login();

  unsigned int selected;
  for(;;) {
    printf("Select an action:\nView balance (0)\nCash withdrawal (1)\nCash deposit (2)\nQuit (3)\nYOUR SELECTION: ");
    scanf("%u", &selected);

    while(selected > 3) {
      printf("Try again (0-3): ");
      scanf("%u", &selected);
    }

    switch(selected) {
      case(0):
        get_balance();
        break;
      case(1):
        withdrawal();
        break;
      case(2):
        deposit();
        break;
      case(3):
        quit();
    }

    num_transactions++;

    unsigned int receipt = 0;
    while(receipt != 1 && receipt != 2) {
      printf("Receipt? (1 for YES, 2 for NO): ");
      scanf("%u", &receipt);
    }
  }
}

void login(void) {
  unsigned int attempts_left = 3;
  unsigned int inputted_pin;

  while(attempts_left > 0) {
    printf("Enter your PIN (%u attempts remaining): ", attempts_left--);
    scanf("%u", &inputted_pin);

    if(inputted_pin == PIN) return;
  }

  puts("You have run out of login attempts. Your session will be terminated.");
  exit(0);
}

void get_balance(void) {
  printf("Current balance: %u\n", balance);
}

void withdrawal() {
  int inputted_withdrawal;
  printf("Enter your withdrawal amount (multiples of 20): ");
  scanf("%d", &inputted_withdrawal);

  while(inputted_withdrawal <= 0 || inputted_withdrawal > withdrawal_limit_remaining || inputted_withdrawal % 20 != 0) {
    if(withdrawal_limit_remaining == 0) {
      puts("Withdrawal limit met. Try again tomorrow.");
      break;
    }

    printf("Invalid input, try again (%u limit remaining). Input withdrawal ammount: ", withdrawal_limit_remaining);
    scanf("%d", &inputted_withdrawal);
  }

  balance -= inputted_withdrawal;
  withdrawal_limit_remaining -= inputted_withdrawal;
  printf("Your withdrawal of $%d was successful.\n", inputted_withdrawal);
}

void deposit() {
  int inputted_deposit;
  printf("Enter your deposit amount: ");
  scanf("%d", &inputted_deposit);

  while(inputted_deposit <= 0 || inputted_deposit > deposit_limit_remaining) {
    if(deposit_limit_remaining == 0) {
      puts("Deposit limit met. Try again tomorrow.");
      break;
    }
    printf("Invalid input, try again (%u limit remaining). Input deposit ammount: ", deposit_limit_remaining);
    scanf("%d", &inputted_deposit);
  }

  balance += inputted_deposit;
  deposit_limit_remaining -= inputted_deposit;
  printf("Your deposit of $%d was successful.", inputted_deposit);
}

void quit(void) {
  printf("Thank you for completing %u transactions.", num_transactions);
  exit(0);
}