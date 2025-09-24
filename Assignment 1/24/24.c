/*
===========================================================================================================================
Name : 24.c
Author : Aman Tiwari
Description :Write a program to create an orphan process.
===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();   // create a child process

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        sleep(10); // child waits so parent exits first
        printf("Child process (PID: %d) with Parent PID: %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent process (PID: %d) exiting...\n", getpid());
        exit(0);  // parent exits immediately
    }

    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air Assignment 1 % gcc 24.c
(base) amantiwari@Amans-MacBook-Air Assignment 1 % ./a.out 
Parent process (PID: 50536) exiting...
(base) amantiwari@Amans-MacBook-Air Assignment 1 % Child process (PID: 50537) with Parent PID: 1

===========================================================================================================================
*/
