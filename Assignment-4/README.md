# **Assignment 4 CS 4328 Lab 4**

## Requirements 
Write a program that takes a reference string and the number
of frames as inputs to simulate page replacement algorithms. 
Suppose the maximum length of a reference string is 20 and there are 5 diffent
numbers of pages. Randomly generate a reference string, e.g. 2 1 3 4 5 2 3 ... 
Take the number of frames as an input from the user. Find out the different number of page faults 
using the Optimal and LRU algorithms.  If there is a tie, use the FIFO algorithm to break 
the tie. Print out the page replacement process and you can see how LRU differs from 
the optimal.   

### **How to run the files!**

1.) First unzip the folder and navigate into the Assignment - 4 folder.  
2.) Once you are inside the Assignment - 4 folder you can begin compiling the assignment files.  
3.) Now you will need to open a terminal in this directory. You can do this by following these instructions:  
   * **Windows 10** ``` hold shift + right click ``` you will see "open powershell window here" click that.  
   * **Mac** ``` right click the Assignment 2 folder and navigate to Services. Here you should see "New Terminal at Folder" ```  
   * **Linux** Distros ```simply right click the Assignment -2 folder and click "Open in Terminal"```    
4.)Once the terminal is open you can start compiling the files. To do so following the instructions below. 
    
To compile the files you can simply copy and paste the commands below:
- Assignment lab4.c
```console
gcc lab4.c
```
To run the executable file that pre.c created input ./a.out in the terminal:
```console
./a.out
```  
You will then be prompt to enter a number of frames.  
Example command formats:  
```console
Welcome to Page Replacement Algorithm Tester.
Please Enter The Number of Frames: 	
```  
You may enter any number to test the algorithms implemented.  
Some sample output  
```console
Welcome to Page Replacement Algorithm Tester.
Please Enter The Number of Frames: 2
The Number of Frames: 2
The Referene String: 4 3 2 4 3 3 1 5 5 2 1 3 1 4 2 1 5 1 5 1 

          LRU Page Replacement Algorithm

 Page |          Frame content   |      Page Faults 
------------------------------------------------------

 4    |  4       -1      |    1

 3    |  4       3       |    2

 2    |  2       3       |    3

 4    |  2       4       |    4

 3    |  3       4       |    5

 3    |  3       4       |    5

 1    |  3       1       |    6

 5    |  5       1       |    7

 5    |  5       1       |    7

 2    |  5       2       |    8

 1    |  1       2       |    9

 3    |  1       3       |    10

 1    |  1       3       |    10

 4    |  1       4       |    11

 2    |  2       4       |    12

 1    |  2       1       |    13

 5    |  5       1       |    14

 1    |  5       1       |    14

 5    |  5       1       |    14

 1    |  5       1       |    14
------------------------------------------------------
 LRU: Total Number of Page Faults: 14


The Referene String: 4 3 2 4 3 3 1 5 5 2 1 3 1 4 2 1 5 1 5 1 

          Optimal Page Replacement Algorithm

 Page |          Frame content   |      Page Faults 
------------------------------------------------------

 4    |  4       -1      |    1

 3    |  4       3       |    2

 2    |  2       -1      |    3

 4    |  2       4       |    4

 3    |  3       -1      |    5

 3    |  3       -1      |    5

 1    |  3       1       |    6

 5    |  5       -1      |    7

 5    |  5       -1      |    7

 2    |  5       2       |    8

 1    |  1       -1      |    9

 3    |  1       3       |    10

 1    |  1       3       |    10

 4    |  4       -1      |    11

 2    |  4       2       |    12

 1    |  1       -1      |    13

 5    |  1       5       |    14

 1    |  1       5       |    14

 5    |  1       5       |    14

 1    |  1       5       |    14
------------------------------------------------------
 Optimal: Total Number of Page Faults: 14


The Referene String: 4 3 2 4 3 3 1 5 5 2 1 3 1 4 2 1 5 1 5 1 

          FIFO Page Replacement Algorithm

 Page |          Frame content   |      Page Faults 
------------------------------------------------------

 4    |   4       -1     |    1

 3    |   4       3      |    2

 2    |   2       3      |    3

 4    |   2       4      |    4

 3    |   3       4      |    5

 3    |   3       4      |    5

 1    |   3       1      |    6

 5    |   5       1      |    7

 5    |   5       1      |    7

 2    |   5       2      |    8

 1    |   1       2      |    9

 3    |   1       3      |    10

 1    |   1       3      |    10

 4    |   4       3      |    11

 2    |   4       2      |    12

 1    |   1       2      |    13

 5    |   1       5      |    14

 1    |   1       5      |    14

 5    |   1       5      |    14

 1    |   1       5      |    14
------------------------------------------------------
 FIFO: Total Number of Page Faults: 14
```