/*
======================================================================================
Name        : 15_parent_to_child.c
Author      : Aman Tiwari
Description : Program demonstrating one-way communication using a pipe.
              Parent process sends data to the child process.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    setbuf(stdout, NULL);

    int pipefd[2];
    char parent_msg[] = " Hello Child, this is your Parent!";
    char buffer[100];

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror(" Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror(" Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process: Read end
        close(pipefd[1]);  
        read(pipefd[0], buffer, sizeof(buffer));
        printf(" Child received: %s\n", buffer);
        close(pipefd[0]);
    } else {
        // Parent process: Write end
        close(pipefd[0]);  
        write(pipefd[1], parent_msg, strlen(parent_msg) + 1);
        printf(" Parent sent: %s\n", parent_msg);
        close(pipefd[1]);
    }

    return 0;
}

/*
======================================================================================
Sample Output:
(base) amantiwari@Amans-MacBook-Air handson2 % gcc 15_parent_to_child.c -o p2c
(base) amantiwari@Amans-MacBook-Air handson2 % ./p2c
 Parent sent:  Hello Child, this is your Parent!
 Child received:  Hello Child, this is your Parent!
======================================================================================
*/
