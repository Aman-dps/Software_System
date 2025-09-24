/*
===========================================================================================================================
Name : 4.c
Author : Aman Tiwari
Description :Write a program to open an existing file with read write mode. Try O_EXCL flag also.
===========================================================================================================================
*/
#include <stdio.h>      
#include <fcntl.h>      
#include <unistd.h>     

int main() {
    int fd;

    
    fd = open("source.txt", O_RDWR);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("File opened successfully. File descriptor = %d\n", fd);

    close(fd);

  
    fd = open("myfile.txt", O_CREAT | O_EXCL | O_RDWR, 0744);

    if (fd == -1) {
        perror("sorry failed");
        return 1;
    }

    printf("File opened successfully. FD = %d\n", fd);

    close(fd);

    return 0;
}
/*
=====OUTPUT================================================================================================================
base) amantiwari@Amans-MacBook-Air 4 % gcc 4_read-write_mode.c
(base) amantiwari@Amans-MacBook-Air 4 % ./a.out                
File opened successfully. File descriptor = 3
File opened successfully. FD = 3
===========================================================================================================================
*/

