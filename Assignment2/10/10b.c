/*
======================================================================================
Name        : 10b_sigint_action.c
Author      : Aman Tiwari
Description : Program to handle SIGINT (Ctrl+C) using sigaction system call.
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Custom handler for SIGINT
void sigint_handler(int signo) {
    printf(" SIGINT received: You pressed Ctrl+C!\n");
}

int main() {
    struct sigaction action;
    action.sa_handler = sigint_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    // Attach handler to SIGINT
    sigaction(SIGINT, &action, NULL);

    printf("Program is running... Press Ctrl+C anytime to send SIGINT.\n");

    while (1) {
        sleep(2);   // keep program alive
    }

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 10b_sigint_action.c -o 10b_sigint
(base) amantiwari@Amans-MacBook-Air list2 % ./10b_sigint
Program is running... Press Ctrl+C anytime to send SIGINT.
^C SIGINT received: You pressed Ctrl+C!
^C SIGINT received: You pressed Ctrl+C!
(base) amantiwari@Amans-MacBook-Air list2 %

======================================================================================
*/
