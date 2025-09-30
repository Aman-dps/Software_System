/*
======================================================================================
Name        : 08b_sigint.c
Author      : Aman Tiwari
Description : Program to handle SIGINT (Ctrl+C) using the signal() system call.
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>   // for exit()
#include <unistd.h>   // for sleep()

void sigint_handler(int signo) {
    printf("\nSignal handler: Caught SIGINT (Interrupt from keyboard)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    // Register the handler for SIGINT
    signal(SIGINT, sigint_handler);

    while (1) {
        printf("Program running... Press Ctrl+C to terminate\n");
        sleep(2);
    }

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 08b_sigint.c -o 08b_sigint
(base) amantiwari@Amans-MacBook-Air list2 % ./08b_sigint
Program running... Press Ctrl+C to terminate
Program running... Press Ctrl+C to terminate
Program running... Press Ctrl+C to terminate
Program running... Press Ctrl+C to terminate
^C
Signal handler: Caught SIGINT (Interrupt from keyboard)

======================================================================================
*/
