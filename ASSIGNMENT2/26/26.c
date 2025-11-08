/*
======================================================================================
Name        : 26
Author      : Aman Tiwari
Description : Send a message to a message queue
======================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    key = ftok("/home/aman-tiwari/Documents/ASSIGNMENT2/26/msgquekey", 'A');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    message.msg_type = 1;
    printf("Enter message to send: ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);

    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd");
        return 1;
    }

    printf("Message sent successfully!\n");
    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/26$ gcc 26.c
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/26$ ./a.out
Enter message to send: hello 
Message sent successfully!
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/26$ 

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41054584 0          aman-tiwari 666        100          1           

======================================================================================
*/
