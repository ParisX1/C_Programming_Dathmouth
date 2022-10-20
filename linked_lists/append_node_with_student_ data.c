/*
Your new task is to write a function append() which takes as input two pointers: 
the first pointer holds the address of the current end of the linked list of 
students, the second pointer points to a newly created student. Your function 
should append this new student to the linked list and return the address 
(a struct student *) of the new end of the list. 

Example
Input: 
25 18 32
Output: 
Petra is 25 years old.
Remi is 18 years old.
Mike is 32 years old.
*/

#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student *append(struct student * end, struct student * newStudptr); 
void copyStr(char* sourceString, char* stringToAssign);
/* add other prototypes here if needed */

int main(void) {
    struct student *start, *newStudptr, *end, *tmp;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);
    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printf("%s is %d years old.\n", start->name, start->age);
    printf("%s is %d years old.\n", start->next->name, start->next->age);
    printf("%s is %d years old.\n", start->next->next->name, start->next->next->age);

    tmp = start->next;
    free(start);
    start = tmp;
    tmp = start->next;
    free(start);
    free(tmp);

    return 0;
}

struct student *createStudent(char studentName[], int studentAge){
    struct student* studentPtr = (struct student*) malloc(sizeof(struct student));
    //studentPtr->name = studentName;
    copyStr(studentName, studentPtr->name);
    studentPtr->age = studentAge;
    return studentPtr;
}

struct student *append(struct student * end, struct student * newStudptr) {
    end->next = newStudptr;
    return newStudptr;
}

void copyStr(char* sourceString, char* stringToAssign) {
    int i = 0;
    while (sourceString[i] != '\0') {
        stringToAssign[i] = sourceString[i];
        i++;
    }
    stringToAssign[i] = '\0';
}