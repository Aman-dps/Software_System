/*
======================================================================================
Name        : 17c
Author      : Aman Tiwari
Description : Program to execute ls -l | wc using fcntl
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[0]);
        int newfd = fcntl(fd[1], F_DUPFD, 1);
        if (newfd != 1) {
            close(1);
            dup(newfd);
        }
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed");
    }

    if (fork() == 0) {
        close(fd[1]);
        int newfd = fcntl(fd[0], F_DUPFD, 0);
        if (newfd != 0) {
            close(0);
            dup(newfd);
        }
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
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/17$ gcc 17c.c
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/17$ ./a.out
      5      38     257
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/17$ 

======================================================================================
*/
