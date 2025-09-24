/*
===========================================================================================================================
Name : 21.c
Author : Aman Tiwari
Description : Write a program, call fork and print the parent and child process id.
===========================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    
    if (pid == 0) {
        
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } 
    else {
        
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air Assignment 1 % gcc 21.c 
(base) amantiwari@Amans-MacBook-Air Assignment 1 % ./a.out
Parent Process: PID = 3888, Child PID = 3896
Child Process: PID = 3896, Parent PID = 1
===========================================================================================================================
*/
