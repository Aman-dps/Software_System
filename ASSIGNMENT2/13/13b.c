/*
======================================================================================
Name        : 13b
Author      : Aman Tiwari
Description : Program sends SIGSTOP signal to target process.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        exit(1);
    }

    pid_t pid = atoi(argv[1]);
    if (kill(pid, SIGSTOP) == 0) {
        printf("Sent SIGSTOP to process %d\n", pid);
    } else {
        perror("kill failed");
    }

    return 0;
}

/*
======================================================================================
Terminal 1
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/13$ ./13a
Program PID: 19925
Waiting for SIGSTOP...
Waiting for SIGSTOP...
Waiting for SIGSTOP...
Terminal 2
OUTPUT:
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/13$ ./a.out 19925
Sent SIGSTOP to process 19925

======================================================================================
*/
