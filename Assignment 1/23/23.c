/*
===========================================================================================================================
Name : 23.c
Author : Aman Tiwari
Description : Write a program to create a Zombie state of the running program.
===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();   

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        
        printf("Child process (PID: %d) exiting...\n", getpid());
        exit(0);  
    } else {
        
        printf("Parent process (PID: %d) sleeping...\n", getpid());
        sleep(10); 
    }

    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air Assignment 1 % gcc 23.c
(base) amantiwari@Amans-MacBook-Air Assignment 1 % ./a.out 
Parent process (PID: 49911) sleeping...
Child process (PID: 49912) exiting...
===========================================================================================================================
*/

