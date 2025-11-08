/*
======================================================================================
Name        : 15
Author      : Aman Tiwari
Description : Program to send data from parent to child process using pipe
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char msg[] = "Hello Child";
    char buf[50];
    pipe(fd);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        close(fd[0]); // close read end
        write(fd[1], msg, strlen(msg) + 1);
    } else {
        // Child process
        close(fd[1]); // close write end
        read(fd[0], buf, sizeof(buf));
        printf("Child received: %s\n", buf);
    }

    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/15$ gcc 15.c
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/15$ ./a.out
Child received: Hello Child

======================================================================================
*/
