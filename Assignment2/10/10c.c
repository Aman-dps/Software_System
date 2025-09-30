/*
======================================================================================
Name        : 10c_sigfpe_action.c
Author      : Aman Tiwari
Description : Example program to handle SIGFPE (Floating Point Exception) using sigaction.
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Custom handler for SIGFPE
void fpe_handler(int signo) {
    printf("SIGFPE caught: Division by zero error!\n");
    exit(1);
}

int main() {
    struct sigaction action;
    action.sa_handler = fpe_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    // Register SIGFPE handler
    sigaction(SIGFPE, &action, NULL);

    int x = 10, y = 0;
    int result = x / y;   // intentional divide by zero
    printf("Result = %d\n", result);

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 10c_sigfpe_action.c -o 10c_sigfpe
(base) amantiwari@Amans-MacBook-Air list2 % ./10c_sigfpe
SIGFPE caught: Division by zero error!
(base) amantiwari@Amans-MacBook-Air list2 %

======================================================================================
*/
