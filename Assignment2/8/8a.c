/*
======================================================================================
Name        : 08a_sigsegv.c
Author      : Aman Tiwari
Description : Program to demonstrate handling of segmentation fault (SIGSEGV) signal.
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>   

void sigsegv_handler(int signo) {
    printf("Signal handler invoked: Caught SIGSEGV (Segmentation Fault)\n");
    exit(EXIT_FAILURE);
}

int main() {
    // Register handler for segmentation fault
    signal(SIGSEGV, sigsegv_handler);

    int *ptr = NULL;
    *ptr = 42;   // Intentional invalid memory access

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 08a_sigsegv.c -o 08a_sigsegv
(base) amantiwari@Amans-MacBook-Air list2 % ./08a_sigsegv
Signal handler invoked: Caught SIGSEGV (Segmentation Fault)

======================================================================================
*/
