/*
======================================================================================
Name        : 19_fifo_creation.c
Author      : Aman Tiwari
Description : Demonstrates different ways to create a FIFO (named pipe):
               a. mknod command
               b. mkfifo command 
               c. use strace command to find out which command (mknod or mkfifo) is better
               d. mknod system call 
               e. mkfifo library function
======================================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int ret;

    printf("Creating FIFO using mknod command...\n");
    ret = system("mknod myfifo1 p");
    if (ret == -1)
        perror("system mknod");

    printf("Creating FIFO using mkfifo command...\n");
    ret = system("mkfifo myfifo2");
    if (ret == -1)
        perror("system mkfifo");

    printf("\nCreating FIFO using mknod() system call...\n");
    if (mknod("myfifo3", S_IFIFO | 0666, 0) == -1)
        perror("mknod syscall");

    printf("Creating FIFO using mkfifo() library function...\n");
    if (mkfifo("myfifo4", 0666) == -1)
        perror("mkfifo library");

    printf("\nListing all FIFOs created:\n");
    system("ls -l myfifo*");

    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari:~/Hands_on_list2$ cc 19_fifo_creation.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./a.out
Creating FIFO using mknod command...
Creating FIFO using mkfifo command...

Creating FIFO using mknod() system call...
Creating FIFO using mkfifo() library function...

Listing all FIFOs created:
prw-rw-r-- 1 aman-tiwari aman-tiwari 0 Sep 30 19:00 myfifo1
prw-rw-r-- 1 aman-tiwari aman-tiwari 0 Sep 30 19:00 myfifo2
prw-rw-r-- 1 aman-tiwari aman-tiwari 0 Sep 30 19:00 myfifo3
prw-rw-r-- 1 aman-tiwari aman-tiwari 0 Sep 30 19:00 myfifo4

======================================================================================
*/
