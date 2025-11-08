/*
======================================================================================
Name        : 18
Author      : Aman Tiwari
Description : Program to count total directories using ls -l | grep ^d | wc with dup2
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);

    if (fork() == 0) {
        close(pipe1[0]);
        dup2(pipe1[1], 1);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls failed");
    }

    if (fork() == 0) {
        close(pipe1[1]);
        dup2(pipe1[0], 0);
        close(pipe1[0]);
        close(pipe2[0]);
        dup2(pipe2[1], 1);
        close(pipe2[1]);
        execlp("grep", "grep", "^d", NULL);
        perror("execlp grep failed");
    }

    if (fork() == 0) {
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[1]);
        dup2(pipe2[0], STDIN_FILENO);
        close(pipe2[0]);
        execlp("wc", "wc", "-l", NULL);
        perror("execlp wc failed");
    }

    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);
    wait(NULL);
    wait(NULL);
    wait(NULL);
    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari:~/Hands_on_list2$ cc 18.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./a.out
0

======================================================================================
*/
