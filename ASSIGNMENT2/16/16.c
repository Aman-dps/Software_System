/*
======================================================================================
Name        : 16
Author      : Aman Tiwari
Description : Program to send and receive data between parent and child using two pipes
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe1[2], pipe2[2];
    char parent_msg[] = "Hello Child";
    char child_msg[] = "Hello Parent";
    char buf[50];

    pipe(pipe1); // parent -> child
    pipe(pipe2); // child -> parent

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        close(pipe1[0]); // close read end of pipe1
        close(pipe2[1]); // close write end of pipe2

        write(pipe1[1], parent_msg, strlen(parent_msg) + 1);
        read(pipe2[0], buf, sizeof(buf));
        printf("Parent received: %s\n", buf);
    } else {
        // Child process
        close(pipe1[1]); // close write end of pipe1
        close(pipe2[0]); // close read end of pipe2

        read(pipe1[0], buf, sizeof(buf));
        printf("Child received: %s\n", buf);

        write(pipe2[1], child_msg, strlen(child_msg) + 1);
    }

    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/16$ gcc 16.c
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/16$ ./a.out
Child received: Hello Child
Parent received: Hello Parent

======================================================================================
*/
