/*
Your goal is to read a 68-word text from the input and then 
print it to the screen backwards. Individual words do not have 
to be spelled backwards, but rather your program should print 
out the last word first, then the second-to-last word, etc. 
No word has more than 40 characters.
*/

#include<stdio.h>

int main(void){
    const int SENTENCE_SIZE = 68;
    const int WORD_SIZE = 40;
    char arrayOfWords[SENTENCE_SIZE][WORD_SIZE];
    int i;

    for (i = 0; i < SENTENCE_SIZE; i++){
        scanf("%s", arrayOfWords[i]);
    }

    for (i = SENTENCE_SIZE - 1; i >=  0; i--){
        printf("%s ", arrayOfWords[i]);
    }
}