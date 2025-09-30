/*
======================================================================================
Name        : 08c_sigfpe.c
Author      : Aman Tiwari
Description : Program to demonstrate handling of floating point exception (SIGFPE).
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>   // for exit()

void fpe_handler(int signo) {
    printf("Signal handler: Caught SIGFPE (Floating Point Exception - divide by zero)\n");
    exit(EXIT_FAILURE);
}

int main() {
    // Register the handler for SIGFPE
    signal(SIGFPE, fpe_handler);

    int num = 10;
    int denom = 0;

    // Intentional division by zero to trigger SIGFPE
    int result = num / denom;

    printf("Result = %d\n", result);  // This line never executes
    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 08c_sigfpe.c -o 08c_sigfpe
(base) amantiwari@Amans-MacBook-Air list2 % ./08c_sigfpe
Signal handler: Caught SIGFPE (Floating Point Exception - divide by zero)

======================================================================================
*/
