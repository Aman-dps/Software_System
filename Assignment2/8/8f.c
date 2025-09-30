/*
======================================================================================
Name        : 08f_sigvtalrm.c
Author      : Aman Tiwari
Description : Program to catch SIGVTALRM using a virtual timer via setitimer().
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>      // for exit()
#include <unistd.h>      // for pause()
#include <sys/time.h>    // for setitimer()

void vtimer_handler(int signo) {
    printf("Signal handler: Caught SIGVTALRM (Virtual timer expired)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    // Register handler for virtual timer
    signal(SIGVTALRM, vtimer_handler);

    struct itimerval vtimer;
    vtimer.it_value.tv_sec = 2;      // Fire after 2 seconds of CPU time
    vtimer.it_value.tv_usec = 0;
    vtimer.it_interval.tv_sec = 0;   // No repeat
    vtimer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &vtimer, NULL);

    printf("Virtual timer scheduled for 2 seconds of CPU time...\n");

    // Busy loop to consume CPU time
    while (1);

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 08f_sigvtalrm.c -o 08f_sigvtalrm
(base) amantiwari@Amans-MacBook-Air list2 % ./08f_sigvtalrm
Virtual timer scheduled for 2 seconds of CPU time...
Signal handler: Caught SIGVTALRM (Virtual timer expired)

======================================================================================
*/
