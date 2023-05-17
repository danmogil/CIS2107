//CIS2017 Lab7: Race
//Daniel Mogil
//03.19.23
//The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
//generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
//controlled using the sleep() function. Sometimes it takes a while due to slippage.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define INT_MIN 1
#define INT_MAX 10

int randomNumberGenerator();
void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int hPos,int tPos);
int min(int hMin, int tMin);

int main(){
    srand((unsigned)time(NULL));

    int hPos = 1;						//hare start position is 1, cannot slip past 1
    int tPos = 1;						//tortoise start position is 1, cannot slip past 1

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");	//the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");	//the spacing is modeled after the sample

    while(hPos < 70 && tPos < 70){
        sleep(1);						//slows down the race
        hareMove(&hPos);
        tortMove(&tPos);
        printRace(hPos,tPos);
    }

    if(hPos >= 70 && tPos >= 70) puts("It's a tie.");
    else if(hPos >= 70) puts("Hare wins. Yuch.");
    else puts("Tortoise Wins!!! YAY!!!");

}

//Finds minimum of hare or tortoise position to decide which position to print first
int min(int hMin, int tMin){
    return (hMin < tMin) ? hMin : tMin;
}

//Prints the position of the H and T
void printRace(int hPos,int tPos){
    int minPos = min(hPos, tPos);
    
    for(int i = 1; i < minPos; i++) printf(" ");
    if(hPos == tPos) {
        puts("OUCH!!!");
        return;
    }

    int maxPos = (hPos > tPos) ? hPos : tPos;
    
    printf("%c", (hPos == minPos) ? 'H' : 'T');

    for(int i = minPos + 1; i < maxPos; i++) printf(" ");

    printf("%c\n", (hPos == maxPos) ? 'H' : 'T');
}

//Controls the tortoise movement
void tortMove(int *tPtr){
    int r = randomNumberGenerator();

    if(r <= 5) *tPtr += 3;
    else if(r <= 7) *tPtr = (*tPtr > 6) ? *tPtr - 6 : 1;
    else *tPtr += 1;
}

//Controls the hare movement
void hareMove(int *hPtr){
    int r = randomNumberGenerator();

    if(r <= 2) *hPtr += 9;
    else if(r <= 5) *hPtr += 1;
    else if(r <= 8) {
        *hPtr -= (r == 6) ? 12 : 2;
        if(*hPtr < 1) *hPtr = 1;
    }
}

//Generates random number from 1-10
int randomNumberGenerator(){
 return rand() % 10 + 1;
}
