/*
===========================================================================================================================
Name : 1a.c
Author : Aman Tiwari
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL

===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_alarm(int sig) {
    printf("ITIMER_REAL: Timer expired!\n");
}

int main() {
    struct itimerval timer;

    signal(SIGALRM, handle_alarm);

    // First expiration after 10 sec and 10 microsec
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    // Interval for periodic timer
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    while (1) {
        pause(); // wait for signal
    }
}
