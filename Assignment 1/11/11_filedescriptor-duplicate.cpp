/*
===========================================================================================================================
Name : 11.c
Author : Aman Tiwari
Description :Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
===========================================================================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd, fd_dup1, fd_dup2, fd_dup3;

    // Open the file in write/append mode (create if it doesn't exist)
    fd = open("test.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // ---------- (a) Using dup ----------
    fd_dup1 = dup(fd);
    if (fd_dup1 < 0) {
        perror("dup");
        return 1;
    }

    // ---------- (b) Using dup2 ----------
    fd_dup2 = dup2(fd, 100);  // duplicate into fd number 100
    if (fd_dup2 < 0) {
        perror("dup2");
        return 1;
    }

    // ---------- (c) Using fcntl ----------
    fd_dup3 = fcntl(fd, F_DUPFD, 200);  // duplicate into an fd >= 200
    if (fd_dup3 < 0) {
        perror("fcntl");
        return 1;
    }

    // Write into file using each descriptor
    write(fd, "Hello_from_fd\n", 14);
    write(fd_dup1, "Hello_from_dup\n", 15);
    write(fd_dup2, "Hello_from_dup2\n", 16);
    write(fd_dup3, "Hello_from_fcntl\n", 17);

    // Close all descriptors
    close(fd);
    close(fd_dup1);
    close(fd_dup2);
    close(fd_dup3);

    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 11 % gcc 11_filedescriptor-duplicate.cpp 
(base) amantiwari@Amans-MacBook-Air 11 % ./a.out
===========================================================================================================================
*/
