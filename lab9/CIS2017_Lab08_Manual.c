/*
 * Name:	Daniel Mogil
 * Section:	01 
 * Lab:  	CIS2107_Lab08_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[]);
void endsWithed(char *string[]);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f\n\n", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series);

    //test for endsWithed
    endsWithed(series);

}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char * s) {

    puts("Upper:");
    for(unsigned int i = 0; i < strlen(s); i++)
        printf("%c", toupper(s[i]));

    puts("\nLower:");
    for(unsigned int i = 0; i < strlen(s); i++)
        printf("%c", tolower(s[i]));

}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    unsigned int sum = 0;

    sum += atoi(s1);
    sum += atoi(s2);
    sum += atoi(s3);
    sum += atoi(s4);

    return sum;
}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    float sum = 0.0;
    
    sum += atof(s1);
    sum += atof(s2);
    sum += atof(s3);
    sum += atof(s4);

    return sum;
}

//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
    switch (strcmp(s1, s2)) {
    case 0:
        puts("s1 == s2");
        break;
    case 1:
        puts("s1 > s2");
        break;
    case -1:
        puts("s1 < s2");
        break;
    }
}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
   char s1_partial[n];
   char s2_partial[n];

   strncpy(s1_partial, s1, n);
   strncpy(s2_partial, s2, n);

   compareStr(s1_partial, s2_partial);
}

//6.(Random Sentences) 
void randomize(void) {
   
   
}

//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
  
  
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    

}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
  
  
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
  
  
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
 
 
}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
   
   
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[]) {
    
 

}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[]) {


}