/*
======================================================================================
Name        : 28
Author      : Aman Tiwari
Description : Remove a message queue using msgctl(IPC_RMID)
======================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    key = ftok("/home/aman-tiwari/Documents/ASSIGNMENT2/26/msgquekey", 'A');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Message queue removed successfully.\n");
    return 0;
}

/*
======================================================================================
OUTPUT:
Terminal 1
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/26$ ./a.out
Enter message to send: Hello
Message sent successfully!
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/26$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41030516 7          aman-tiwar 666        100          1           

aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/26$ 

Terminal 2

aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/28$ gcc 28.c
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/28$ ./a.out
Message queue removed successfully.
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/28$ 

Terminal 1 after

aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/26$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages   
======================================================================================
*/
