/* 
* Program 2:
* Write a c program to set up a child-TO-parent pipe; the child 
* should 'exec' to perform a "pre" process and its output should be 
* connected to the pipe connected to the parent, which should 'exec' to 
* perform a "sort" process.
* 
* Author: Alexander Gonzalez
* CS 4328.751 
* Professor: Dr. Xiao Chen
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{

    int pipe_fd[2];
    pid_t pid;
    

    if (pipe(pipe_fd) == -1)
    {
        perror("\nError with pipe: check README");
        exit(1);
    }pid = fork();
    if (pid == 0)
    {
        close(1);
        dup(pipe_fd[1]);
        close(pipe_fd[1]);
        close(pipe_fd[0]);
        execl("./pre", "pre", NULL);
    }
    else if (pid > 0)
    {
        close(0);
        dup(pipe_fd[0]);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        execl("./sort", "sort", NULL);
    }
    else
    {
        perror("\n Fork failed: check README");
        exit(2);
    }
    return (0);
}
