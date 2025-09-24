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

int main() {
    int fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
   
    

    write(fd, "1", 1);  // store first ticket number
    close(fd);

    printf("Ticket file initialized with 1\n");
    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 17 % gcc 17-initializetickete.c 
(base) amantiwari@Amans-MacBook-Air 17 % ./a.out
Ticket file initialized with 1
===========================================================================================================================
*/
