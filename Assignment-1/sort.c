/* 
* * Author: Alexander Gonzalez
* CS 4328.751 
* Professor: Dr. Xiao Chen
* The second program "sort.c" reads in a list of names from stdin and 
* outputs them in an alphabetical order. Assume there are no more than 10 
* names and the sequence is read until an EOF is encountered. 
* 
* For the above example, the output should be:
* 
* John
* Mary
* Susan
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char name[10];
}Name;
int main()
{
    
    Name tempStudent,studentArr[10];
    int i,j,counter = 0;
    
    while(counter < 10 && !feof(stdin))
    {
        
        scanf("%s",studentArr[counter].name);
        counter++;
    }
    
    for (i = 0; i < counter; i++)
    {
        for(j = 0; j < counter; j++)
        {
            if (strcmp(studentArr[i].name, studentArr[j].name) < 0)
            {
                strcpy(tempStudent.name, studentArr[i].name);
                strcpy(studentArr[i].name, studentArr[j].name);
                strcpy(studentArr[j].name, tempStudent.name);
            }
        }
    }
    
    for (i = 0; i < counter; i++)
    {
        printf("%s\n",studentArr[i].name);
    }
    return 0;
}
