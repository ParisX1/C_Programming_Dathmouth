/*
The goal of this problem is to find the smallest integer in a list of numbers.
*/

#include<stdio.h>

int min(int num1, int num2);

int main(void){
    int numNumbers;
    int minNum;
    int i;
    
    // Number of ints to read
    scanf("%d", &numNumbers);
    
    // Store values
    int numberArray[numNumbers];

    for (i = 0; i < numNumbers; i++) {
        scanf("%d", &numberArray[i]);
    }

    // Find min
    minNum = numberArray[0];
    for (i = 1; i < (numNumbers); i++) {
        minNum = min(minNum, numberArray[i]);
    }
    
    // Print result
    printf("%d", minNum);
    
    return 0;
}

int min(int num1, int num2) {
    if (num1 < num2)
        return num1;
    else 
        return num2;
}