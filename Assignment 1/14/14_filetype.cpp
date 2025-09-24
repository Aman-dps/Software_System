/*
===========================================================================================================================
Name : 14.c
Author : Aman Tiwari
Description :Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
===========================================================================================================================
*/
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &fileStat) == -1) {
        perror("stat");
        return 1;
    }

    if (S_ISREG(fileStat.st_mode))
        printf("%s is a regular file.\n", argv[1]);
    else if (S_ISDIR(fileStat.st_mode))
        printf("%s is a directory.\n", argv[1]);
    else if (S_ISCHR(fileStat.st_mode))
        printf("%s is a character device.\n", argv[1]);
    else if (S_ISBLK(fileStat.st_mode))
        printf("%s is a block device.\n", argv[1]);
    else if (S_ISFIFO(fileStat.st_mode))
        printf("%s is a FIFO (named pipe).\n", argv[1]);
    else if (S_ISLNK(fileStat.st_mode))
        printf("%s is a symbolic link.\n", argv[1]);
    else if (S_ISSOCK(fileStat.st_mode))
        printf("%s is a socket.\n", argv[1]);
    else
        printf("%s: Unknown file type.\n", argv[1]);

    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 14 % gcc 14_filetype.cpp
(base) amantiwari@Amans-MacBook-Air 14 % ./a.out testfile.txt 
testfile.txt is a regular file.
===========================================================================================================================
*/
