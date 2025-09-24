/*
===========================================================================================================================
Name : 5.c
Author : Aman Tiwari
Description :Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
===========================================================================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>


int main() {
    while (1) {
        for (int i = 1; i <= 5; ++i) { 
            char filename[15];
            snprintf(filename, sizeof(filename), "new_file_%d", i);
            printf("File %d created \n",i);
            int fd = open(filename, O_CREAT | O_WRONLY, 0644);
            if (fd < 0) {
                printf("Error creating files");
            }
            sleep(3);
            close(fd);
        }
        exit(0);
    }
    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 5 % gcc 5.c
(base) amantiwari@Amans-MacBook-Air 5 % ./a.out
File 1 created 
File 2 created 
File 3 created 
File 4 created 
File 5 created 
===========================================================================================================================
*/