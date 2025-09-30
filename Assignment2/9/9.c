/*
======================================================================================
Name        : 09_sigint_ignore_reset.c
Author      : Aman Tiwari
Description : Demonstrates ignoring SIGINT for a duration, then restoring default action.
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Phase 1: SIGINT will be ignored for 10 seconds. Try pressing Ctrl+C now...\n");
    signal(SIGINT, SIG_IGN);   // Ignore SIGINT
    sleep(10);

    printf("\nPhase 2: SIGINT restored to default action. Press Ctrl+C to exit.\n");
    signal(SIGINT, SIG_DFL);   // Restore default behavior

    // Infinite loop until user interrupts
    while (1) {
        sleep(1);
    }

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 09_sigint_ignore_reset.c -o 09_sigint
(base) amantiwari@Amans-MacBook-Air list2 % ./09_sigint
Phase 1: SIGINT will be ignored for 10 seconds. Try pressing Ctrl+C now...
^C^C^C
Phase 2: SIGINT restored to default action. Press Ctrl+C to exit.
^C
(base) amantiwari@Amans-MacBook-Air list2 %

======================================================================================
*/
