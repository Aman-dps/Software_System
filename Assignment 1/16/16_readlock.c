/*
===========================================================================================================================
Name : 16a.c
Author : Aman Tiwari
Description : Write a program to perform mandatory locking.
            a. Implement write lock
            b. Implement read lock

===========================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("test.txt", O_RDWR | O_CREAT, 0666);

    struct flock lock;
    lock.l_type = F_RDLCK;     // read lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Trying to set read lock...\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Read lock acquired! Press Enter to unlock...\n");
    getchar();

    lock.l_type = F_UNLCK;    
    fcntl(fd, F_SETLK, &lock);
    printf("Lock released.\n");

    close(fd);
    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 16 % gcc 16_readlock.c 
(base) amantiwari@Amans-MacBook-Air 16 % ./a.out
Trying to set read lock...
Read lock acquired! Press Enter to unlock...

Lock released.
===========================================================================================================================
*/

