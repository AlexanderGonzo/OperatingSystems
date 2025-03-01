/* Assignment One: Program 3
 *
 * The program will take a UNIX command from the command line
 * and fork() a child to execute it.
 * It will use argc and argv[] in the main function to pass parameters
 *
 * When the child process is executing the command, the parent process will
 * simply wait for the termination of the child.
 *
 * The Process id of the parent and the child should be printed out useing
 * getpid() and getppid() functions.
 *
 * Author: Alexander Gonzalez
 * CS 4328.751 
 * Professor: Dr. Xiao Chen
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{

    pid_t pid;
    pid = fork();

    if (argc < 2)
    {
        fprintf(stderr, "Usage: ./a.out 'unix command' ...\n");
        exit(EXIT_FAILURE);
    }
    if (pid < 0)
    {
        fprintf(stderr, "fork failed");
        exit(0);
    }
    else if (pid == 0)
    {
        printf("Child Process: pid = %u\n\n", getpid());
        argv[argc + 1] = NULL;
        execvp(argv[1], argv + 1);
    }
    else
    {
        wait(NULL);
        printf("\n");
        printf("Parent Process: pid = %u\n", getppid());
    }
    return 0;
}