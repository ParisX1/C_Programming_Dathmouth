/*
Your new task is to write a function printStudents() which takes as input a 
pointer that holds the address of the start of a linked list of students. 
Your function should then print this list of students to the screen as 
specified in the example below. Your function should not return anything.

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

struct student *createStudent(char studentName[50], int studentAge);
struct student * append(struct student * end, struct student * newStudptr); 
void printStudents(struct student *start);
void copyStr(char* sourceString, char* stringToAssign);
/* add other prototypes here if needed*/

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

    printStudents(start);
    tmp = start->next;

    free(start);

    start = tmp;
    tmp = start->next;

    free(start);
    free(tmp);

    return 0;
}

void printStudents(struct student *start) {
    while (start != NULL) {
        printf("%s is %d years old.\n", start->name, start->age);
        start = start->next;
    }
}

struct student *createStudent(char studentName[], int studentAge){
    struct student* studentPtr = (struct student*) malloc(sizeof(struct student));
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