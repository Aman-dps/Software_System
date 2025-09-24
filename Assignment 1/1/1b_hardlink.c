/*
===========================================================================================================================
Name : 1.b
Author : Aman Tiwari
Description : 1. Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)
===========================================================================================================================
*/
#include<unistd.h>
#include <stdio.h>

int main() {
    
    if (link("q1.txt", "hardlink.txt") == -1) {
        perror("Failed");
        return 1;
    }
    printf("Hard link created\n");
    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air software system % gcc hardlink.c
(base) amantiwari@Amans-MacBook-Air software system % ./a.out       
Hard link created
(base) amantiwari@Amans-MacBook-Air software system % ls -l
-rw-r--r--@  1 amantiwari  admin    206 Aug 24 14:42 hardlink.c
-rw-r--r--@  2 amantiwari  admin     16 Aug 24 14:49 hardlink.txt
===========================================================================================================================
*/
