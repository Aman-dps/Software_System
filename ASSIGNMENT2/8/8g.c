/*
======================================================================================
Name        : 08g_sigprof.c
Author      : Aman Tiwari
Description : Program to catch SIGPROF using a profiling timer with setitimer().
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/time.h>

void prof_timer_handler(int signo) {
    printf("Signal handler: Caught SIGPROF (Profiling Timer Expired)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    struct itimerval prof_timer;

    // Register handler for SIGPROF
    signal(SIGPROF, prof_timer_handler);

    // Set profiling timer: first expiration after 1 second, repeat every 1 second
    prof_timer.it_value.tv_sec = 1;
    prof_timer.it_value.tv_usec = 0;
    prof_timer.it_interval.tv_sec = 1;
    prof_timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &prof_timer, NULL);

    // Busy loop to allow timer to expire
    while (1) { }

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 08g_sigprof.c -o 08g_sigprof
(base) amantiwari@Amans-MacBook-Air list2 % ./08g_sigprof
Signal handler: Caught SIGPROF (Profiling Timer Expired)

======================================================================================
*/
