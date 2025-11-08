/*
======================================================================================
Name        : 29
Author      : Aman Tiwari
Description : Create shared memory, attach it, write data, and detach it
======================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key;
    int shmid;
    char *data;

    key = ftok("/home/aman-tiwari/Documents/ASSIGNMENT2/29/sharedmemorykey", 'A');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    shmid = shmget(key, 1024, 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)-1) {
        perror("shmat");
        return 1;
    }

    strcpy(data, "Hello Shared Memory!");
    printf("Data written to shared memory: %s\n", data);

    shmdt(data);
    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/29$ gcc 29.c
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/29$ ./a.out
Data written to shared memory: Hello Shared Memory!
======================================================================================
*/
