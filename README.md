# Implementation of Paging and Segmentation Scheme in C
This is a proof of concept used to show the implementation of the Paging and Segmentation scheme in C. The program allows us to visualize the method in which paging and segmentation might take place in an Operating System. This is a small project made for the course Operating Systems as part of a group project.

## Utilization of the code
#### How to use?
* First run the command  
```gcc algorithms.c getDataFromFile.c main.c memoryListFunctions.c myheader.h```  
* Then run the file in the following way  
```./a.out```  

#### What it contains?
The ```files/``` directory contains information about processes and their required memory. You can also input the process memory normally through the console by selecting the option of input method of console when the program opens.

#### Input methods
The program can take inputs in two methods
* Input can be given normally through an interactive console
* Input can also be given by specifying the filename. Eg.```files/process_2.txt```

#### What types of Algorithms?
In this small project we have implemented the visualization of the Paging and Segmentation scheme as done by an operating system. The program takes multiple processes and their required memory as input and outputs the visualization table.

## Footer
Team Members
* [Abhay Sahni](https://github.com/abhaysahni)
* Abhishek Vashisht
* Kshitij Rana
* [Shivang Bharadwaj](https://github.com/reficul31)