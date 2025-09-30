/*
======================================================================================
Name        : 13a_sigstop.c
Author      : Aman Tiwari
Description : Program that attempts to catch SIGSTOP using sigaction. 
              However, SIGSTOP cannot be caught, blocked, or ignored.
              This demonstrates that the handler will never be invoked.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Attempted handler (will never be called for SIGSTOP)
void handler(int signo) {
    printf(" Tried to catch signal %d\n", signo);
}

int main() {
    setbuf(stdout, NULL);

    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    // Try to register handler for SIGSTOP
    if (sigaction(SIGSTOP, &sa, NULL) == -1) {
        perror("sigaction");
    }

    printf(" Program 1 running (PID: %d). Waiting for SIGSTOP...\n", getpid());

    while (1) sleep(1);

    return 0;
}

/*
======================================================================================
Sample Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 13a_sigstop.c -o prog1
(base) amantiwari@Amans-MacBook-Air list2 % gcc 13b_sigstop.c -o prog2
(base) amantiwari@Amans-MacBook-Air list2 % ./prog1
 Program 1 running (PID: 5123). Waiting for SIGSTOP...

(base) amantiwari@Amans-MacBook-Air list2 % ./prog2 5123
Sent SIGSTOP to process 5123

[1]+  Stopped                 ./prog1
======================================================================================
*/
