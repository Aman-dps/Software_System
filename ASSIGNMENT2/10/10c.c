/*
======================================================================================
Name        : 10c_sigfpe
Author      : Aman Tiwari
Description : Program to catch SIGFPE using sigaction system call
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGFPE: Floating Point Exception (Divide by Zero)\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGFPE, &sa, NULL);

    int a = 5, b = 0, c;
    c = a / b;

    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari:~/Hands_on_list2$ vim 10c.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ cc 10c.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./a.out
Caught SIGFPE: Floating Point Exception (Divide by Zero)

======================================================================================
*/
