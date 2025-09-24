/*
===========================================================================================================================
Name : 17.c
Author : Aman Tiwari
Description :Write a program to simulate online ticket reservation. Implement write lock. Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
===========================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd;
    char buf[10];
    int ticket;
    struct flock lock;

    fd = open("ticket.txt", O_RDWR);
    if (fd < 0) {
        perror("open failed");
        return 1;
    }

    // setup write lock
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    // acquire lock
    fcntl(fd, F_SETLKW, &lock);

    // read ticket number
    int n = read(fd, buf, sizeof(buf));
    buf[n] = '\0';
    ticket = atoi(buf);

    // increment ticket
    ticket++;

    // move file pointer back to beginning
    lseek(fd, 0, SEEK_SET);

    // write updated ticket
    sprintf(buf, "%d", ticket);
    write(fd, buf, strlen(buf));

    printf("Your ticket number: %d\n", ticket);

    // release lock
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 17 % gcc 17-reserve_ticket.c   
(base) amantiwari@Amans-MacBook-Air 17 % ./a.out
Your ticket number: 2
===========================================================================================================================
*/