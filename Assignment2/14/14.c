/*
======================================================================================
Name        : 14_pipe_demo.c
Author      : Aman Tiwari
Description : Simple program to demonstrate pipe communication between parent and child.
              Parent writes into the pipe, child reads from it and displays the message.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];  
    char msg_to_write[] = "📨 Message flowing through the pipe!";
    char msg_to_read[100];

    if (pipe(pipefd) == -1) {
        perror(" pipe creation failed");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror(" fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process: Read end
        close(pipefd[1]);  
        read(pipefd[0], msg_to_read, sizeof(msg_to_read));
        printf(" Child received: %s\n", msg_to_read);
        close(pipefd[0]);
    } else {
        // Parent process: Write end
        close(pipefd[0]);  
        write(pipefd[1], msg_to_write, strlen(msg_to_write) + 1);
        printf(" Parent sent: %s\n", msg_to_write);
        close(pipefd[1]);
    }

    return 0;
}

/*
======================================================================================
Sample Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 14_pipe_demo.c -o pipe_demo
(base) amantiwari@Amans-MacBook-Air list2 % ./pipe_demo
 Parent sent:  Message flowing through the pipe!
 Child received:  Message flowing through the pipe!
======================================================================================
*/
