/*
===========================================================================================================================
Name : 9.c
Author : Aman Tiwari
Description :Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
===========================================================================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    struct stat info;

    // Get details of "test.txt"
    if (stat("source.txt", &info) == -1) {
        perror("stat");
        return 1;
    }

    printf("Inode: %ld\n", info.st_ino);
    printf("Hard Links: %ld\n", info.st_nlink);
    printf("UID: %d\n", info.st_uid);
    printf("GID: %d\n", info.st_gid);
    printf("Size: %ld bytes\n", info.st_size);
    printf("Last Access: %s", ctime(&info.st_atime));
    printf("Last Modify: %s", ctime(&info.st_mtime));
    printf("Last Change: %s", ctime(&info.st_ctime));

    return 0;
}
/*
=====OUTPUT================================================================================================================
base) amantiwari@Amans-MacBook-Air 9 % ./a.out            
Inode: 66271236
Hard Links: 1
UID: 501
GID: 80
Size: 23 bytes
Last Access: Sun Sep  7 11:56:11 2025
Last Modify: Sun Sep  7 11:56:09 2025
Last Change: Sun Sep  7 11:56:09 2025
===========================================================================================================================
*/
