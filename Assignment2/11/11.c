/*
======================================================================================
Name        : 11_sigint_toggle.c
Author      : Aman Tiwari
Description : Program to first ignore SIGINT (Ctrl+C), then restore its default action 
              using the sigaction() system call.
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction action;

    // Step 1: Ignore SIGINT
    action.sa_handler = SIG_IGN;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    printf("SIGINT is currently ignored. Press Ctrl+C (no effect)...\n");
    sleep(5);

    // Step 2: Restore default handler
    action.sa_handler = SIG_DFL;
    sigaction(SIGINT, &action, NULL);

    printf("SIGINT default action restored. Press Ctrl+C to exit.\n");

    while (1) {
        sleep(1);
    }

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 11_sigint_toggle.c -o 11_sigint_toggle
(base) amantiwari@Amans-MacBook-Air list2 % ./11_sigint_toggle
 SIGINT is currently ignored. Press Ctrl+C (no effect)...
^C SIGINT default action restored. Press Ctrl+C to exit.
^C
(base) amantiwari@Amans-MacBook-Air list2 %

======================================================================================
*/
