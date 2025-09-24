/*
===========================================================================================================================
Name : 26.c
Author : Aman Tiwari
Description :Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
===========================================================================================================================
*/
#include<unistd.h>
#include <stdio.h>

int main() {
    
    if (symlink("q1.txt", "softlink.txt") == -1) {
        perror("Failed");
        return 1;
    }
    printf("Soft link created\n");
    return 0;
}
/*
=====OUTPUT================================================================================================================
 gcc softlink.c
(base) amantiwari@Amans-MacBook-Air software system % ./a.out       
Soft link created
base) amantiwari@Amans-MacBook-Air software system % ls -l
-rw-r--r--@  1 amantiwari  admin    209 Aug 24 14:14 softlink.c
lrwxr-xr-x   1 amantiwari  admin      6 Sep  6 12:43 softlink.txt -> q1.txt
===========================================================================================================================
*/
