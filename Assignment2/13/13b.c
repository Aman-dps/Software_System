/*
======================================================================================
Name        : 13b_sigstop_sender.c
Author      : Aman Tiwari
Description : Program that sends a SIGSTOP signal to another process using kill() system call.
              Demonstrates that SIGSTOP cannot be caught or ignored in the target process.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t target_pid = atoi(argv[1]);

    if (kill(target_pid, SIGSTOP) == -1) {
        perror(" kill failed");
        exit(EXIT_FAILURE);
    }

    printf(" Sent SIGSTOP to process %d\n", target_pid);
    return 0;
}

/*
======================================================================================
Sample Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 13a_sigstop.c -o prog1
(base) amantiwari@Amans-MacBook-Air list2 % gcc 13b_sigstop_sender.c -o prog2

(base) amantiwari@Amans-MacBook-Air list2 % ./prog1
 Program 1 running (PID: 5214). Waiting for SIGSTOP...

(base) amantiwari@Amans-MacBook-Air list2 % ./prog2 5214
 Sent SIGSTOP to process 5214

[1]+  Stopped                 ./prog1
======================================================================================
*/
