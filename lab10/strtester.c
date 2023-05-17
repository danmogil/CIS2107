#include "stdio.h"
#include "strings.h"

/*
  Daniel Mogil
  04/24/23
  CIS2107
  String Library

  You'll create your own library of string functions. You'll have the opportunity to practice manipulating
  strings and managing memory. Additionally, you'll learn the role of header and library files.
*/


int main(void) {

  char *s1 = "SFDDerere";
  char *s2 = "de12";
  
  printf("%d", all_letters(s1)); // 1
  printf("%d", all_letters(s2)); // 0

  char *s3 = "abcdef";
  printf("%d", num_in_range(s3, 'c', 'e')); // 3

  char *s4 = "abcdef";
  printf("%d", diff("test", "testing")); // 3


  char *s5 = "abcdef";
  shorten("abcdef", "4");
  printf("%s", s5); // abcd

  printf("%d", len_diff("abcdef", "abcd")); // 2

  char *s6 = "  abc";
  rm_left_space(s6);
  printf("%s", s6); // "abc"

  char *s7 = "abc  ";
  rm_right_space(s7);
  printf("%s", s7); // "abc"

  char *s8 = "  abc  ";
  rm_space(s8);
  printf("%s", s8); // "abc"


  printf("%d", find("abcdef", "bc")); // 1

  printf("%d", is_empty("1")); // 0
  printf("%d", is_empty(" ")); // 1

  printf("%s", str_zip("Spongebob", "Patrick")); // SPpaotnrgiecbkob

  char *s9 = "abc";
  capitalize(s9);
  printf("%s", s9); // "ABC"

  printf("%d", strcmp_ign_case("ABC", "abc")); // 0
  printf("%d", strcmp_ign_case("ABCD", "abc")); // 1
  printf("%d", strcmp_ign_case("AB", "abc")); // -1

  char *s10 = "Brubeck";
  take_last(s10, 5);
  printf("%s", s10); // "ubeck"


  char *s11 = "test";
  pad(s11, 6);
  printf("%s", s11); // "test  "

  printf("%d", ends_with_ignore_case("testing", "ing")); // 1
  printf("%d", ends_with_ignore_case("testing", "ed")); // 0

  printf("%s", repeat("test", 3, ',')); // test,test,test

}