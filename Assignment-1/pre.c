/*
* Author: Alexander Gonzalez
* CS 4328.751 
* Professor: Dr. Xiao Chen
* The first program "pre.c"
* should read in a list of student names and their GPAs. You can make up a list. To be simple, you
* can make student name one word in lower cases. We assume there are at most 10 students in the list.
* The input ends when an EOF is encountered. The output of the program should display the students
* whose GPA is above 3.0.
* */
#include <stdio.h>
#include <string.h>
typedef struct
{
    char name[10];
    float gpa;

} Student;

int main()
{
    Student studentArr[9];
    int count = 0;
    int i;

    while (!feof(stdin))
    {
        scanf("%s %f", studentArr[count].name, &studentArr[count].gpa);
        count++;
    }

    for (i = 0; i < count; i++)
    {
        if (studentArr[i].gpa >= 3.0){
            printf("%s\n", studentArr[i].name);
        }
    }
    return 0;
}
