/*
======================================================================================
Name        : 24
Author      : Aman Tiwari
Description : Create a message queue and print its key and ID
======================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    key = ftok(".", 'A');   // Generate a unique key
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    msgid = msgget(key, 0666 | IPC_CREAT);  // Create message queue
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}

/*
======================================================================================
OUTPUT:
SIGNMENT2/24$ gcc 24.c
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/24$ ./a.out
Message Queue Key: 1090724829
Message Queue ID: 0

======================================================================================
*/
