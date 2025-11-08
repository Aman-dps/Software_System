/*
======================================================================================
Name        : 17a
Author      : Aman Tiwari
Description : Program to execute ls -l | wc using dup (fixed to behave correctly)
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[0]);
        close(1);
        dup(fd[1]);
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed");
    }

    if (fork() == 0) {
        close(fd[1]);
        close(0);
        dup(fd[0]);
        close(fd[0]);
        execlp("wc", "wc", NULL);
        perror("execlp failed");
    }

    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/17$ gcc 17a.c
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/17$ ./a.out
      5      38     257

======================================================================================
*/
