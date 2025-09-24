/*
===========================================================================================================================
Name : 22.c
Author : Aman Tiwari
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
===========================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    pid_t pid;

    
    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open failed");
        return 1;
    }

    
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        
        char msg[] = "Hello from Child\n";
        write(fd, msg, strlen(msg));
    } else {.
        
        char msg[] = "Hello from Parent\n";
        write(fd, msg, strlen(msg));
    }

    close(fd);
    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air Assignment 1 % gcc 22.c 
(base) amantiwari@Amans-MacBook-Air Assignment 1 % ./a.out
Hello from Parent
Hello from Child
===========================================================================================================================
*/
