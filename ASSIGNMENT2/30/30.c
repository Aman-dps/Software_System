/*
======================================================================================
Name        : 30
Author      : Aman Tiwari
Description : Read data from shared memory and print it
======================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

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

    printf("Data read from shared memory: %s\n", data);

    shmdt(data);
    return 0;
}

/*
======================================================================================
OUTPUT:
Terminal 1
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/29$ gcc 29.c
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/29$ ./a.out
Data written to shared memory: Hello Shared Memory!

Terminal 2
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/30$ gcc 30.c
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/30$ ./a.out
Data read from shared memory: Hello Shared Memory!
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/30$ 
======================================================================================
*/
