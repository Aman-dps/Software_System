/*
===========================================================================================================================
Name : 27_c.c
Author : Aman Tiwari
Description :Write a program to execute ls -Rl by the following system calls
c. execvp

===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // to import execvp()

int main()
{
    char *argv[] = {"ls", "-Rl", NULL};

    printf("Executing ls -Rl using execvp.\n");

    execvp("ls", argv); // searches PATH
    perror("execvp failed");

    return 1;
}
/*
=====OUTPUT================================================================================================================
base) amantiwari@Amans-MacBook-Air 27 % vim 27_e.c
(base) amantiwari@Amans-MacBook-Air 27 % gcc 27_e.c
(base) amantiwari@Amans-MacBook-Air 27 % ./a.out   
Executing ls -Rl using execvp.
total 112
-rw-r--r--@ 1 amantiwari  admin   3320 Sep 23 18:39 27_a.c
-rw-r--r--@ 1 amantiwari  admin   3297 Sep 23 18:41 27_b.c
-rw-r--r--@ 1 amantiwari  admin   3407 Sep 23 21:16 27_c.c
-rw-r--r--@ 1 amantiwari  admin   1187 Sep 23 21:20 27_d.c
-rw-r--r--@ 1 amantiwari  admin    648 Sep 23 21:21 27_e.c
-rwxr-xr-x  1 amantiwari  admin  33656 Sep 23 21:22 a.out
===========================================================================================================================
*/