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
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Now executing hello program...\n");

    // execl(path, program_name, argument, NULL)
    execl("./hello","hello","Aman", NULL);

    
   
    return 1;
}
/*
=====OUTPUT================================================================================================================
 gcc 26_b.c         
(base) amantiwari@Amans-MacBook-Air Assignment 1 % ./a.out   
Now executing hello program...
Hello, World!
===========================================================================================================================
*/

