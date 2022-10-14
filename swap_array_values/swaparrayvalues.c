/*
Within this program, we will pass an array with 6 integers to a function, have the 
function swap the first and last integer, the second and the second to last integer, 
the third and the third to last integer.

The function is called reverseArray and doesn't return anything (void). It should 
take one parameter, representing the array of integers. 

The main function first reads 6 integers from the input, and assigns them to the 
array. The main function then calls reverseArray, passing the array as an argument.

The main function then prints the reversed array.

Examples
Input: 1 2 3 4 5 6
Output: 6 5 4 3 2 1

Input: 9 12 3 25 11 5
Output:5 11 25 3 12 9
*/

#include<stdio.h>

void reverseArray(int* ptr);

int  main(void){
    const int ARRAY_SIZE = 6;
    int array[ARRAY_SIZE];
    int i;
    for(i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &array[i]);
    }
    reverseArray(array);
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
}

void reverseArray(int* ptr){
    int arraySize = 6;
    int i = 0;
    int temp;
    while ( i < (arraySize / 2) ){
        temp = *(ptr + i);
        *(ptr + i) = *(ptr + (arraySize - i - 1));
        *(ptr + arraySize - i - 1) = temp;
        i++;
    }
}