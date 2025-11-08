/*
======================================================================================
Name        : 23
Author      : Aman Tiwari
Description : Print maximum files a process can open and size of a pipe
======================================================================================
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <fcntl.h>

int main() {
    struct rlimit l;

    getrlimit(RLIMIT_NOFILE, &l);
    printf("Maximum number of files a process can open: Soft=%ld Hard=%ld\n", 
           (long)l.rlim_cur, (long)l.rlim_max);

    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }
    int pipe_size = fcntl(fd[0], F_GETPIPE_SZ);
    printf("Size of pipe (circular buffer): %d bytes\n", pipe_size);

    close(fd[0]);
    close(fd[1]);
    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/23$ gcc 23.c
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/23$ ./a.out
Maximum number of files a process can open: Soft=1048576 Hard=1048576
Size of pipe (circular buffer): 65536 bytes

======================================================================================
*/
