/*
In this problem you will continue developing the data feature which you started 
implementing in the previous problem. You will implement a "tomorrow" feature in 
the C programming language via a function called "advanceDay()". 
The function advanceDay() should take as input a date (stored in a struct date) 
and return the date of the following day. You do not have to take into account 
leap years (although you may if you wish to). That is, it is okay for your 
function to always return March 1 as the day following February 28, no matter 
the year.

Examples
Input:
2018 10 2
Output:
10/02/2018                                                                      
10/03/2018

Input:
2018 12 31
Output:
12/31/2018                                                                      
01/01/2019

*/

#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date); 
int isThirtyEOM(int month);

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

void printDate(struct date dateObj){
    printf("%02d/%02d/%02d\n", dateObj.month, dateObj.day, dateObj.year);
}

void readDate(struct date* datePrt){
    scanf("%d %d %d", &datePrt->year, &datePrt->month, &datePrt->day);
}

struct date advanceDay(struct date dateObj){
    int isEndOfMonth = 0; // Bool for end of month flag
    
    // Check for end of month
    if (dateObj.day == 28 && dateObj.month == 2)                    isEndOfMonth = 1;
    else if (dateObj.day == 30 && isThirtyEOM(dateObj.month)==1)    isEndOfMonth = 1;
    else if (dateObj.day == 31)                                     isEndOfMonth = 1;

    if (isEndOfMonth) {
        dateObj.day = 1;
        dateObj.month++;
    }
    
    // Check for new year
    if (dateObj.month == 13) {
        dateObj.month = 1;
        dateObj.year++;
    }
    return dateObj;
}

int isThirtyEOM(int month) {
    if ((month == 4 || month == 6 || month ==  9 || month ==  11))  return 1;
    else                                                            return 0;
    // return (month == 4 || month == 6 || month ==  9 || month ==  11);
}