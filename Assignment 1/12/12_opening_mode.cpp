/*
===========================================================================================================================
Name : 12.c
Author : Aman Tiwari
Description : Write a program to find out the opening mode of a file. Use fcntl.
===========================================================================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_RDWR);   // open file in read-write mode
    int flags = fcntl(fd, F_GETFL);      // get file status flags

    if ((flags & O_ACCMODE) == O_RDONLY)
        printf("Opened in READ only mode\n");
    else if ((flags & O_ACCMODE) == O_WRONLY)
        printf("Opened in WRITE only mode\n");
    else if ((flags & O_ACCMODE) == O_RDWR)
        printf("Opened in READ and WRITE mode\n");

    close(fd);
    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 12 % gcc 12_opening_mode.cpp 
(base) amantiwari@Amans-MacBook-Air 12 % ./a.out                
Opened in READ and WRITE mode
===========================================================================================================================
*/
