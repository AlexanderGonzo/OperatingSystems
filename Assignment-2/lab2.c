#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){

    /* Variables given by professor: used for command and parsing */
    char *path, *argv[20], buffer[80], n, *p ,*out_Path;
    int m, status, inword, continu, j, k;

    /*Variables for Piping and the Pipe Initialization,
      Starting point for argument locations in argv[], 
      Flags that will handle redirection of input and output.
        */
    pid_t pid;
    int pCounter, pipes;
    int right_fd[2], left_fd[2];
    int st[20] = {0};
    int inputFlag, outputFlag; 

    while (1){

        /* Resets parsing and pipe variables for every loop, 
           start parsing at buffer, 
           redirection flags.
        */
        inword = continu = m = pCounter = pipes = pid = j = k = 0;
        p = buffer;
        inputFlag = outputFlag = 0;

        /*Shell*/
        printf("\nshhh> ");

        /* Command parsing given by Professor */
        while ((n = getchar()) != '\n' || continu)
        {
            if (n == ' ') {
                if (inword)
                {
                    inword = 0;
                    *p++ = 0;
                }
            }
            else if (n == '\n')
                continu = 0;
            else if (n == '\\' && !inword)
                continu = 1;
            else {
                if (!inword)
                {
                    inword = 1;
                    argv[m++] = p;
                    *p++ = n;
                }
                else
                    *p++ = n;
            }
        }
        *p++ = 0;
        argv[m] = 0;

        /* Exit Prompt defined by project requirements */
        if (strcmp(argv[0], "exit") == 0){
            exit(0);
        }
        /* Redirection Manager: Handles Pipes, Input, and Output Redirection*/
        while(argv[pCounter] != 0){

            /* Pipe Handler*/
            if(strcmp(argv[pCounter], "|") == 0){
                argv[pCounter] = 0;
                st[pipes + 1] = pCounter + 1;
                pipes++;
            } 
            /* Input Redirection Handler*/
            else if(strcmp(argv[pCounter], "<") == 0){
                path = strdup(argv[pCounter + 1]);
                argv[pCounter] = 0;
                inputFlag = 1;
            }
            /* Output Redirection Handler */
            else if(strcmp(argv[pCounter], ">") == 0){
                out_Path = strdup(argv[pCounter + 1]);
                argv[pCounter] = 0;
                outputFlag = 1;
            }/* Normal Commands i.e no pipes or redirections */
            else{
                st[pCounter] = pCounter;
            }
            ++pCounter;
        }
        /* Pipe Counting. Needed to know for processes */
        for (j = 0; j <= pipes; ++j){
            if(pipes > 0 && j != pipes){
                pipe(right_fd);
            }

            /* Process Management: Handles Parent and Children processes  */
            switch (pid = fork()){
            case -1:
                perror("Fork has failed");
                break;
            case 0: 
                /* Child will check for Redirection and Execute the commands given by users*/
                /* Checking for  Input Redirection */
                if ((j == 0) && (inputFlag == 1))
                {
                    int inputFile = open(path, O_RDONLY, 0400);
                    if (inputFile == -1)
                    {
                        perror("Input file failed to open\n");
                        return (EXIT_FAILURE);
                    }
                    close(0);
                    dup(inputFile);
                    close(inputFile);
                }
                /* Checking for Output Redirection */
                if ((j == pipes) && (outputFlag == 1))
                {
                    int outputFile = creat(out_Path, 0700);
                    if (outputFile < 0)
                    {
                        perror("The Output file has failed to open.\n");
                        return (EXIT_FAILURE);
                    }
                    close(1);
                    dup(outputFile);
                    close(outputFile);
                }
                /* Closes and Opens pipes depending on reading or writing */
                if (pipes > 0)
                {
                    if (j == 0)
                    {
                        close(1);
                        dup(right_fd[1]);
                        close(right_fd[1]);
                        close(right_fd[0]);
                    }
                    else if (j < pipes)
                    {
                        close(0);
                        dup(left_fd[0]);
                        close(left_fd[0]);
                        close(left_fd[1]);
                        close(1);
                        dup(right_fd[1]);
                        close(right_fd[0]);
                        close(right_fd[1]);
                    }
                    else
                    {
                        close(0);
                        dup(left_fd[0]);
                        close(left_fd[0]);
                        close(left_fd[1]);
                    }
                }
                /* Execution of the commands. */
                execvp(argv[st[j]], &argv[st[j]]);
                perror("Execution of command failed\n");
                break;
            default:
                if (j > 0)
                {
                    close(left_fd[0]);
                    close(left_fd[1]);
                }
                left_fd[0] = right_fd[0];
                left_fd[1] = right_fd[1];

                wait(&status);
                break;
            }
        }
        /* This will clean the arguments for the next run */
        for(k = 0; k < 20; ++k){
            argv[k] = 0;
        }
    }
}
