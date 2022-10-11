/*
Wwrite a C-program that uses a recursive function called "sumOfDigits()" 
to compute the sum of the digits of a number. 
To do so, your main function should first read an integer number as input 
and then call sumOfDigits(), which should in turn call itself until there are 
no digits left to sum, at which point the final sum should display to the user.

Examples:
sumOfDigits(6452) = 2 + sumOfDigits(645)
sumOfDigits(645) = 5 + sumOfDigits(64)
*/

#include<stdio.h>

int sumOfDigits(int number);

int main(void){
    int inputNumber;
    int digitSum;
    scanf("%d", &inputNumber);
    digitSum = sumOfDigits(inputNumber);
    printf("%d", digitSum);
    return 0;
}

int sumOfDigits(int number){
    int currentDigit = number % 10;
    if ( (number != 10) && (currentDigit % 10 == 0) ) {
        return number;
    }
    else {
        number = (number - currentDigit) / 10;
        return currentDigit + sumOfDigits(number);
    }
}