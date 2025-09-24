/*
===========================================================================================================================
Name : 18.c
Author : Aman Tiwari
Description :Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
===========================================================================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h> 

int lock_record(int fd, off_t offset, int length, int lock_type) {
    struct flock lock;
    lock.l_type = lock_type;   
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = length;
    return fcntl(fd, F_SETLKW, &lock);
}

void access_record(int fd, int record_num, int lock_type, const char *data) {
    int offset = record_num * 20;
    if (lock_record(fd, offset, 20, lock_type) == -1) {
        printf("Lock failed\n");
        exit(1);
    }
    if (lock_type == F_WRLCK) {
        lseek(fd, offset, SEEK_SET);
        write(fd, data, 20);
    } else {
        char buffer[20 + 1];
        lseek(fd, offset, SEEK_SET);
        read(fd, buffer, 20);
        buffer[20] = '\0';
        printf("Record %d: %s\n", record_num+1, buffer);
    }
    lock_record(fd, offset, 20, F_UNLCK);
}

int main() {
    const char *filename = "textfile.txt";
    int fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        printf("Failed to open file");
        exit(1);
    }
    char initial_records[3][20] = {
        "|Original Record 1|",
        "|Original Record 2|",
        "|Original Record 3|"
    };
    for (int i = 0; i < 3; ++i) {
        lseek(fd, i * 20, SEEK_SET);
        write(fd, initial_records[i], 20);
    }

    access_record(fd, 0, F_WRLCK, "|Modified Record 1|");
    access_record(fd, 0, F_RDLCK, NULL);
    access_record(fd, 1, F_RDLCK, NULL);
    access_record(fd, 2, F_WRLCK, "|Modified Record 3|");
    access_record(fd, 2, F_RDLCK, NULL);
    close(fd);
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 18 % gcc 18.c
(base) amantiwari@Amans-MacBook-Air 18 % ./a.out 
Record 1: |Modified Record 1|
Record 2: |Original Record 2|
Record 3: |Modified Record 3|
===========================================================================================================================
*/