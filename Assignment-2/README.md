# **Assignment 2 CS 4328 Lab 2**

## Requirements 
Write a small shell - called shhh - that has the 
following capabilities:  
1. Can execute a command with the accompanying arguments.  
2. Recognize multiple pipe requests and handle them.  
3. Recognize redirection requests and handle them.  
4. Type "exit" to quit the shhh shell.  

### **How to run the files!**

1.) First unzip the folder and navigate into the Assignment - 2 folder.  
2.) Once you are inside the Assignment -2 folder you can begin compiling the assignment files.  
3.) Now you will need to open a terminal in this directory. You can do this by following these instructions:  
   * Windows 10 ``` hold shift + right click ``` you will see "open powershell window here" click that.  
   * Mac ``` right click the Assignment 2 folder and navigate to Services. Here you should see "New Terminal at Folder" ```  
   * Linux Distros ```simply right click the Assignment -2 folder and click "Open in Terminal"```    
4.)Once the terminal is open you can start compiling the files. To do so following the instructions below. 
    
To compile the files you can simply copy and paste the commands below:
- Assignment lab2.c
```console
gcc lab2.c
```
To run the executable file that pre.c created input ./a.out in the terminal:
```console
./a.out
```  
You will then be prompt with shhh> and you may begin entering tabs  
Example command formats:  
```console
shhh>  cat fred.c
shhh>  ls -al  > output.dat
shhh>  ls | wc  
shhh>  linect < file.dat | stats   > out.dat
shhh>  prog -x  | prog1 | prog2 -2 | prog3 
shhh>  ls -al |  grep -n net  | wc > out.dat		
```  
I have also provided some binary files inside the zip folder so you can also run the following commands:  
```console
./pre <input.txt | ./sort > output.txt
```  
### **IMPORTANT!!**
when entering commands with input/output redirection be sure to have a space in between the redirection and the file name  
Correct Example  
```console
ls > output.txt
```  
Incorrect Example  
```console
ls >output.txt 
or
ls>output.txt
```