/*
======================================================================================
Name        : 13a
Author      : Aman Tiwari
Description : Program tries to catch SIGSTOP signal.
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    printf("Program PID: %d\n", getpid());
    signal(SIGSTOP, handler);   // attempt to catch SIGSTOP (will not work)

    while (1) {
        printf("Waiting for SIGSTOP...\n");
        sleep(2);
    }
    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/13$ gcc 13a.c
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/13$ ./a.out
Program PID: 18738
Waiting for SIGSTOP...
Waiting for SIGSTOP...
Waiting for SIGSTOP...
Waiting for SIGSTOP...
^C

======================================================================================
*/
