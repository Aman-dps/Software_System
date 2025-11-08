/*
======================================================================================
Name        : 14
Author      : Aman Tiwari
Description : Program to create a pipe, write to it, read from it, and display on monitor
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char msg[] = "Hello Pipe";
    char buf[50];

    pipe(fd);

    write(fd[1], msg, strlen(msg) + 1);
    read(fd[0], buf, sizeof(buf));

    printf("Message from pipe: %s\n", buf);

    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/14$ gcc 14.c
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/14$ ./a.out
Message from pipe: Hello Pipe

======================================================================================
*/
