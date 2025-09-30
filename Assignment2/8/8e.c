/*
======================================================================================
Name        : 08e_setitimer.c
Author      : Aman Tiwari
Description : Program to handle SIGALRM using the setitimer() system call.
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>      // for exit()
#include <unistd.h>      // for pause()
#include <sys/time.h>    // for setitimer()

void timer_handler(int signo) {
    printf("Signal handler: Caught SIGALRM (Timer expired)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    // Register handler for SIGALRM
    signal(SIGALRM, timer_handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 3;       // First timer expiration after 3 seconds
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;    // No periodic repeat
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    printf("Timer scheduled for 3 seconds...\n");
    pause();   // Wait for the signal

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 08e_setitimer.c -o 08e_setitimer
(base) amantiwari@Amans-MacBook-Air list2 % ./08e_setitimer
Timer scheduled for 3 seconds...
Signal handler: Caught SIGALRM (Timer expired)

======================================================================================
*/
