/*
======================================================================================
Name        : 31b
Author      : Aman Tiwari
Description : Read data from the shared memory written by another process (Process 2)
======================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key;
    int shmid;
    char *data;

    key = ftok(".", 'B');
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

    printf("Data read from shared memory: %s\n", data);

    shmdt(data);
    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari:~/Hands_on_list2$ cc 31b.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./a.out
Data read from shared memory: Shared Memory Communication

======================================================================================
*/
