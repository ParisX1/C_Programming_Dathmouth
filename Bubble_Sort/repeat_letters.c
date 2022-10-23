#include<stdio.h>

void bubbleSort(char stringToSort[]){
    // Get array size
    int stringSize = 0;
    char tempChar;
    while (stringToSort[stringSize] != '\0'){
        stringSize++;
    }

    // Sort array
    for (int i = 0; i < (stringSize - 1); i++){
        for (int j = 0; j < (stringSize - 1); j++){
            if (stringToSort[j] > stringToSort[j + 1]){
                tempChar = stringToSort[j];
                stringToSort[j] = stringToSort[j + 1];
                stringToSort[j + 1] = tempChar;
            }
        }
    }
}

int countMaxLetters(char inputStr[]){
    int countRepeats = 0;
    int letterCount = 1;
    int i = 0;

    while (inputStr[i + 1] != '\0'){ 
        while (inputStr[i] == inputStr[i+1]){
            i++;
            letterCount++;
        }
        if (letterCount >= 2) countRepeats++;
        letterCount = 1;
        i++;
    }
    return countRepeats;
}

int main(void){
    char inputStr[20];
    int maxLetters;
    scanf("%s", inputStr);
    bubbleSort(inputStr);
    maxLetters = countMaxLetters(inputStr);
    printf("%d\n", maxLetters);
    return 0;
}


/*
~~ CODE FROM CODE CAST ~~

You are still conducting linguistic research! This time, you'd like to write a program to 
find out how many letters occur multiple times in a given word. Your program should read a 
word from the input and then sort the letters of the word alphabetically (by their ASCII codes). 
Next, your program should iterate through the letters of the word and compare each letter 
with the one following it. If these equal each other, you increase a counter by 1, making 
sure to then skip ahead far enough so that letters that occur more than twice are not counted 
again. You may assume that the word you read from the input has no more than 50 letters, and 
that the word is all lowercase.

*/