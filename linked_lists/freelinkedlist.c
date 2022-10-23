/*
Your current task is to write a function freeStudents() which takes as 
input a pointer that holds the address of the start of a linked list of 
students. Your function should then free the space allocated for each 
student in this list of students. Your function should not return anything.
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
void freeStudents(struct student *start);

int main(void) {
    struct student *start, *newStudptr, *end;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    freeStudents(start);

    return 0;
}

void freeStudents(struct student *start){
    struct student* tempPtr;
    while (start != NULL){
        tempPtr = start->next;
        free(start);
        start = tempPtr;
    }
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