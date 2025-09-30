/*
======================================================================================
Name        : 10a_sigsegv_action.c
Author      : Aman Tiwari
Description : Example program to handle segmentation fault (SIGSEGV) using sigaction().
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Custom signal handler for segmentation fault
void segv_handler(int signo) {
    printf("SIGSEGV caught: Invalid memory access detected!\n");
    exit(1);
}

int main() {
    struct sigaction act;
    act.sa_handler = segv_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    // Register SIGSEGV handler
    sigaction(SIGSEGV, &act, NULL);

    // Intentionally cause segmentation fault
    int *ptr = NULL;
    *ptr = 42;

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 10a_sigsegv_action.c -o 10a_sigsegv
(base) amantiwari@Amans-MacBook-Air list2 % ./10a_sigsegv
 SIGSEGV caught: Invalid memory access detected!
(base) amantiwari@Amans-MacBook-Air list2 %

======================================================================================
*/
