/*
===========================================================================================================================
Name : 3.c
Author : Aman Tiwari
Description :Write a program to create a file and print the file descriptor value. Use creat ( ) system call
===========================================================================================================================
*/
#include <stdio.h>      
#include <fcntl.h>      
#include <unistd.h>     

int main() {
    int f; 

   
    f= creat("source.txt", 0744);

    if (f == -1) {
        perror("failed"); 
        return 1;         
    }

    printf("File descriptor = %d\n", f);

    close(f); 
    return 0;  
}
/*
=====OUTPUT================================================================================================================
base) amantiwari@Amans-MacBook-Air software system % gcc file_descriptor.c 
(base) amantiwari@Amans-MacBook-Air software system % ./a.out              
File descriptor = 3
===========================================================================================================================
*/
