/*
===========================================================================================================================
Name : 27_c.c
Author : Aman Tiwari
Description :Write a program to execute ls -Rl by the following system calls
c. execv

===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include  <unistd.h>

int main(){
	char *arr[] = {"ls", "-Rl", NULL};
 

	printf("Executing ls -Rl using execv.");

        execv("/bin/ls", arr);
        return 1;
}
/*
=====OUTPUT================================================================================================================
base) amantiwari@Amans-MacBook-Air 27 % ./a.out
total 104
-rw-r--r--@ 1 amantiwari  admin   3320 Sep 23 18:39 27_a.c
-rw-r--r--@ 1 amantiwari  admin   3297 Sep 23 18:41 27_b.c
-rw-r--r--@ 1 amantiwari  admin   3407 Sep 23 21:16 27_c.c
-rw-r--r--@ 1 amantiwari  admin    836 Sep 23 21:20 27_d.c
-rwxr-xr-x  1 amantiwari  admin  33592 Sep 23 21:20 a.out
===========================================================================================================================
*/