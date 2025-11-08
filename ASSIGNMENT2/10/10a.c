/*
======================================================================================
Name        : 10a_sigsegv
Author      : Aman Tiwari
Description : Program to catch SIGSEGV using sigaction system call
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGSEGV: Segmentation Fault\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGSEGV, &sa, NULL);

    int *p = NULL;
    *p = 10;

    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari:~/Hands_on_list2$ cc 10a.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./a.out
Caught SIGSEGV: Segmentation Fault
aman-tiwari@aman-tiwari:~/Hands_on_list2$ 

======================================================================================
*/
