/*
===========================================================================================================================
Name : 26.c
Author : Aman Tiwari
Description :Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
===========================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Executing ls:\n");
    execl("/bin/ls", "ls", NULL);
    perror("execl failed");
    return 1;
}
/*
=====OUTPUT================================================================================================================
base) amantiwari@Amans-MacBook-Air 26 % gcc 26_a.c 
(base) amantiwari@Amans-MacBook-Air 26 % ./a.out
Executing ls:
26_a.c  26_b.c  a.out
===========================================================================================================================
*/
