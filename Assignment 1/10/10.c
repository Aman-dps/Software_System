/*
===========================================================================================================================
Name : 10.c
Author : Aman Tiwari
Description :10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
    const char *filename = "textfile.txt";
    int fd = open(filename, O_RDWR, 0644);
    if(fd==-1){
        printf("Error while opening\n");
    }
    const char *data1 = "1234567890";
    if (write(fd, data1, 10) != 10) {
        printf("Unable to write first 10 bytes\n");
        close(fd);
        exit(1);
    }
    int new_offset = lseek(fd, 10, SEEK_CUR);
    printf("new offset: %ld\n", (long)new_offset);

    const char *data2 = "abcdefghij";
    if (write(fd, data2, 10) != 10) {
        printf("Unable to write next 10 bytes\n");
        close(fd);
        exit(1);
    }

    close(fd);
    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 10 % gcc 10.c 
(base) amantiwari@Amans-MacBook-Air 10 % ./a.out 
new offset: 20
===========================================================================================================================
*/