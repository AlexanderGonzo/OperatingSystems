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
    char *path, *argv[20], buffer[80], n, *parse;
    int m, status, inword, continu , j, k;

    /*Flags that will handle redirection of input and output. */
    char *in_Path, *out_Path;
    int inputRedirectionFlag, outputRedirectionFlag; 

    /*Variables for Piping and the Pipe Initialization  */
    pid_t pid;
    int pCounter, pipes;
    int right_fd[2], left_fd[2];

    /* Starting point for argument locations in argv[] */
    int startArgs[20] = {0};

    while (1){

        /* resets parsing and pipe variables for every loop */
        inword = continu = m = pCounter = pipes = pid = j = k = 0;
        /* redirection flags */
        inputRedirectionFlag = outputRedirectionFlag = 0;
        /* start parsing at bufferferfer */
        parse = buffer;

        /*Shell*/
        printf("\nshhh> ");

        /* Command parsing given by Professor */
        while ((n = getchar()) != '\n' || continu)
        {
            if (n == ' ') {
                if (inword)
                {
                    inword = 0;
                    *parse++ = 0;
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
                    argv[m++] = parse;
                    *parse++ = n;
                }
                else
                    *parse++ = n;
            }
        }
        *parse++ = 0;
        argv[m] = 0;

        /* Exit Prompt defined by project requirements  */
        if (strcmp(argv[0], "exit") == 0){
            exit(0);
        }
        /* Redirection Management*/
        while(argv[pCounter] != 0){

            /* Pipe Handler*/
            if(strcmp(argv[pCounter], "|") == 0){
                argv[pCounter] = 0;
                startArgs[pipes + 1] = pCounter + 1;
                pipes++;
            } 
            /* Input Redirection Handler*/
            else if(strcmp(argv[pCounter], "<") == 0){
                in_Path = strdup(argv[pCounter + 1]);
                argv[pCounter] = 0;
                inputRedirectionFlag = 1;
            }
            /* Output Redirection Handler */
            else if(strcmp(argv[pCounter], ">") == 0){
                out_Path = strdup(argv[pCounter + 1]);
                argv[pCounter] = 0;
                outputRedirectionFlag = 1;
            }else{
                startArgs[pCounter] = pCounter;
            }
            pCounter++;
        }
        for (j = 0; j <= pipes; j++){
            if(pipes > 0 && j != pipes){
                pipe(right_fd);
            }

            switch (pid = fork())
            {
            case -1:
                perror("Fork has failed");
                break;
            case 0: /* Child will check for Redirection and Execute */
                /* Checking for  Input Redirection */
                if ((j == 0) && (inputRedirectionFlag == 1))
                {
                    int inputFile = open(in_Path, O_RDONLY, 0400);
                    if (inputFile == -1)
                    {
                        perror("Input file failed to open\n");
                        return (EXIT_FAILURE);
                    }
                    close(1);
                    dup(inputFile);
                    close(inputFile);
                }
                /* Checking for Output Redirection */
                if ((j == pipes) && (outputRedirectionFlag == 1))
                {
                    int outputFile = creat(out_Path, 0700);
                    if (outputFile < 0)
                    {
                        perror("The Output file has failed to open.\n");
                        return (EXIT_FAILURE);
                    }
                    close(0);
                    dup(outputFile);
                    close(outputFile);
                }
                if (pipes > 0)
                {
                    if (j == 0)
                    {
                        close(0);
                        dup(right_fd[0]);
                        close(right_fd[0]);
                        close(right_fd[1]);
                    }
                    else if (j < pipes)
                    {
                        close(1);
                        dup(left_fd[1]);
                        close(left_fd[1]);
                        close(left_fd[0]);
                        close(0);
                        dup(right_fd[0]);
                        close(right_fd[1]);
                        close(right_fd[0]);
                    }
                    else
                    {
                        close(1);
                        dup(left_fd[1]);
                        close(left_fd[1]);
                        close(left_fd[0]);
                    }
                }
                execvp(argv[startArgs[j]], &argv[startArgs[j]]);
                perror("Execution of command failed\n");
                break;
            default:
                if (j > 0)
                {
                    close(left_fd[1]);
                    close(left_fd[1]);
                }
                left_fd[1] = right_fd[1];
                left_fd[0] = right_fd[0];

                wait(&status);
                break;
            }
        }
        for(k = 0; k < 20; k++){
            argv[k] = 0;
        }
    }
}
