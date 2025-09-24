/*
===========================================================================================================================
Name : 8.c
Author : Aman Tiwari
Description :Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
===========================================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    const char *filename = "textfile.txt";
    int bytes;
    char buffer[256];
    int fd = open(filename, O_RDONLY);
    if(fd==-1){
        printf("Error opening file\n");
    }
    while ((bytes=read(fd, buffer, 256)) >0){
        write(STDOUT_FILENO, buffer, bytes);    
    }
    close(fd);
    return 0;
}
/*
=====OUTPUT================================================================================================================
base) amantiwari@Amans-MacBook-Air 8 % gcc 8.c 
(base) amantiwari@Amans-MacBook-Air 8 % ./a.out         
hello from textfile
===========================================================================================================================
*/