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

void handle_vtalrm(int sig) {
    printf("ITIMER_VIRTUAL: Timer expired!\n");
}

int main() {
    struct itimerval timer;

    signal(SIGVTALRM, handle_vtalrm);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    // Busy loop to consume CPU time (since ITIMER_VIRTUAL runs only while process executes)
    while (1) {
        for (volatile long i = 0; i < 100000000; i++); 
    }
}
