#include<stdio.h>

int main(void){

    int numbersToRead;
    int total = 0;
    int currentNum;
    char dataType;
    int inputsCorrect = 1;
    int currentSpace = 0;
    const int INTEGER_SPACE = 4;
    const int DECIMAL_SPACE = 8;
    const int CHAR_SPACE = 1;

    scanf("%d", &numbersToRead);
    int i;
    for(i = 0; i < numbersToRead; i++){
        scanf("%d %c", &currentNum, &dataType);
        if (dataType == 'i')        currentSpace = INTEGER_SPACE;
        else if (dataType == 'd')   currentSpace = DECIMAL_SPACE;
        else if (dataType == 'c')   currentSpace = CHAR_SPACE;
        else                        inputsCorrect = 0;
        total = total + (currentSpace * currentNum);
    }

    if (inputsCorrect == 1)     printf("%d bytes", total);
    else                        printf("Invalid tracking code type");

    return 0;
}