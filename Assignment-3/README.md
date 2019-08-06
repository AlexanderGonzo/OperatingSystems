# **Assignment 3 CS 4328 Lab 3**

## Requirements 
Three students are competing for a scholarship of $4,000. Suppose the 
scholarship is awarded in a FCFS fashion. Each time each one can get
25% of the available fund.

Use three threads to simulate this. Each thread should execute in a loop.
When the fund runs out, stop all the threads and terminate the program.
And then you add all the money given out, if the total does not add up
to $4000, your program is not correct.

a. Write the program without considering the mutual exclusion. Run the
program several times to show that mutual exclusion is not guaranteed and
the result is not correct.

b. Write the program again considering the mutual exclusion. Run the 
program several times to show that mutual exclusion is guaranteed.

To make longer execution of threads, use some sleep(n) functions in 
the program. Experiment with n to choose the best one to show the 
results. 

### **How to run the files!**

1.) First unzip the folder and navigate into the Assignment - 3 folder.  
2.) Once you are inside the Assignment - 3 folder you can begin compiling the assignment files.  
3.) Now you will need to open a terminal in this directory. You can do this by following these instructions:  
   * **Windows 10** ``` hold shift + right click ``` you will see "open powershell window here" click that.  
   * **Mac** ``` right click the Assignment 2 folder and navigate to Services. Here you should see "New Terminal at Folder" ```  
   * **Linux** Distros ```simply right click the Assignment -2 folder and click "Open in Terminal"```    
4.)Once the terminal is open you can start compiling the files. To do so following the instructions below. 
    
To compile the files you can simply copy and paste the commands below:
- Assignment lab3.c. ***lab3a*** does not contain the mutex/sleep and ***lab3b*** does contain a mutex  
```console
gcc lab3a.c

or

gcc lab3b.c
```
To run the executable file that lab3a/b.c created input ./a.out in the terminal:
```console
./a.out
```  
You will then be presented with either a correct answer or an incorrect answer depending on which .c file you ran.   