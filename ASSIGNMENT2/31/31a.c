/*
======================================================================================
Name        : 31a
Author      : Aman Tiwari
Description : Create and write to a shared memory segment (Process 1)
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

    key = ftok(".", 'B');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)-1) {
        perror("shmat");
        return 1;
    }

    printf("Enter data to write to shared memory: ");
    fgets(data, 1024, stdin);

    printf("Data written successfully.\n");
    shmdt(data);
    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/31$ gcc 31a.c -o a
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/31$ gcc 31b.c -o b
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/31$ ./a
Enter data to write to shared memory: Hello from a
Data written successfully.
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/31$ ./b
Data read from shared memory: Hello from a

aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/31$ 

======================================================================================
*/
