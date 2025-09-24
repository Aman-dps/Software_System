/*
===========================================================================================================================
Name : 1c.c
Author : Aman Tiwari
Description :Create the following types of a files using (i) shell command (ii) system call
c.FIFO (mkfifo Library Function or mknod system call)
===========================================================================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
   

    if (mkfifo("myfifo", 0744) == -1) {
        perror("mkfifo");
        return 1;
    }
    printf("FIFO created\n");
    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air software system % gcc fifo_file.c
(base) amantiwari@Amans-MacBook-Air software system % ./a.out        
FIFO created
(base) amantiwari@Amans-MacBook-Air software system % ls
myfifo
===========================================================================================================================
*/
