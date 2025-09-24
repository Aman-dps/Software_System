/*
===========================================================================================================================
Name : 13.c
Author : Aman Tiwari
Description :Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not .
===========================================================================================================================
*/
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
    fd_set fds;
    struct timeval tv;
    int result;

    FD_ZERO(&fds);         // clear set
    FD_SET(0, &fds);       // watch stdin (fd = 0)

    tv.tv_sec = 10;        // wait for 10 seconds
    tv.tv_usec = 0;

    printf("Type something within 10 seconds...\n");

    result = select(1, &fds, NULL, NULL, &tv);

    if (result == 0)
        printf("Timeout! No input.\n");
    else if (result > 0)
        printf("Input is available!\n");
    else
        printf("Error in select.\n");

    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 13 % gcc 13_wait_select.cpp 
(base) amantiwari@Amans-MacBook-Air 13 % ./a.out               
Type something within 10 seconds...
hello
Input is available!
(base) amantiwari@Amans-MacBook-Air 13 % hello
(base) amantiwari@Amans-MacBook-Air 13 % ./a.out
Type something within 10 seconds...
Timeout! No input.
===========================================================================================================================
*/
