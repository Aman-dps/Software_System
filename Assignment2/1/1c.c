/*
===========================================================================================================================
Name : 1a.c
Author : Aman Tiwari
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL

===========================================================================================================================
*/#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_prof(int sig) {
    printf("ITIMER_PROF: Timer expired!\n");
}

int main() {
    struct itimerval timer;

    signal(SIGPROF, handle_prof);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    // Do some CPU + syscalls (so both user and kernel time are consumed)
    while (1) {
        for (volatile long i = 0; i < 100000000; i++); 
        write(STDOUT_FILENO, ".", 1); 
    }
}
