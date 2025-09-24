/*
===========================================================================================================================
Name : 16b.c
Author : Aman Tiwari
Description : Write a program to perform mandatory locking.
            a. Implement write lock
            b. Implement read lock

===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    struct flock lock;

    
    fd = open("file_lock.txt", O_WRONLY | O_CREAT, 0744);
    

    
    lock.l_type = F_WRLCK;   
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;        
    lock.l_len = 0;          
    lock.l_pid = getpid();  

   fcntl(fd,F_SETLKW,&lock); 
    

    printf("Write lock set. Press enter to unclock\n");
    getchar();

    
    lock.l_type = F_UNLCK;
   
        

    printf("File unlocked.\n");
    close(fd);
    return 0;


}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 16 % gcc 16_writelock.c 
(base) amantiwari@Amans-MacBook-Air 16 % ./a.out           
Write lock set. Press enter to unclock

File unlocked.
===========================================================================================================================
*/
