/*
===========================================================================================================================
Name : 7.c
Author : Aman Tiwari
Description :Write a program to copy file1 into file2 ($cp file1 file2).
===========================================================================================================================
*/
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2;
    char buffer[1024];
    int n;

    fd1 = open("file1.txt", O_RDONLY);                 // open file1 in read-only mode
    fd2 = open("file2.txt", O_WRONLY | O_CREAT, 0644); // open/create file2 in write mode

    while ((n = read(fd1, buffer, sizeof(buffer))) > 0) {
        write(fd2, buffer, n); // write data into file2
    }

    close(fd1);
    close(fd2);

    return 0;
}
/*
=====OUTPUT================================================================================================================
base) amantiwari@Amans-MacBook-Air 7 % vim file1.txt
(base) amantiwari@Amans-MacBook-Air 7 % gcc 7_copyfile.c 
(base) amantiwari@Amans-MacBook-Air 7 % ./a.out
===========================================================================================================================
*/
