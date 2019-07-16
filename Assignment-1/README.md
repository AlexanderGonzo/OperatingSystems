# Assignment 1



## Requirements

CS 4328 Lab 1 

1). The first program "pre.c" 
should read in a list of student names and their GPAs. You can make up a list. To be simple, you 
can make student name one word in lower cases. We assume there are at most 10 students in the list. 
The input ends when an EOF is encountered. The output of the program should display the students 
whose GPA is above 3.0.

 
For example, the following are the inputs to "pre.c" from keyboard: 


Susan 3.9 
Mary  3.6 
Bob   2.8
John  4 
Ctrl-D (to terminate the input.)
         
    then "pre.c" produces the output: 
Susan
Mary
John

Note: an EOF is usually 'sent' to a process by hitting a CTRL_D.  
If you type stty -a on your unix command line, you can get info that 
tells you which keyboard keys mean what. FYI, in c, to put values to 
standard_out  use printf().  To get values from standard_in use scanf() 
or getchar(). 

2). The second program "sort.c" reads in a list of names from stdin and 
outputs them in an alphabetical order. Assume there are no more than 10 
names and the sequence is read until an EOF is encountered. 

For the above example, the output should be:

John
Mary
Susan
 

2. Write a c program to set up a child-TO-parent pipe; the child 
should 'exec' to perform a "pre" process and its output should be 
connected to the pipe connected to the parent, which should 'exec' to 
perform a "sort" process.

3. Write a program to take a UNIX command from the command line
and fork() a child to execute it. The command can be a simple 
command like: $ls or $ps, Or it can be a command with options such as
$ls -t -l. Use argc and argv[] in the main function to pass parameters.
When the child process is executing the command, the parent process 
simply waits for the termination of the child process. The process 
id of the parent and the child should be printed out using getpid() and
getppid() functions.


### How to run the files.
1.) First unzip the folder and navigate into the Assignment - 1 folder.
2.) Once you are inside the Assignment -1 folder you can begin compiling the assignment files.
3.) Now you will need to open a terminal in this directory. You can do this by following these instructions:  
   * Windows 10 ``` hold shift + right click ``` you will see "open powershell window here" click that.  
   * Mac ``` right click the Assignment 1 folder and navigate to Services. Here you should see "New Terminal at Folder" ```  
   * Linux Distros ```simply right click the Assignment -1 folder and click "Open in Terminal"  
    
To compile the files you will use gcc in the terminal:
```
gcc pre.c
``
To run the executable file that was created input ./a.out in the terminal:
```
./a.out
```


