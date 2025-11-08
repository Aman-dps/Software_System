/*
======================================================================================
Name        : 01_timer_real
Author      : Aman Tiwari
Description : Program to set an interval timer using ITIMER_REAL with 10 sec and 10 microsec
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handler(int a) {
    printf("ITIMER_REAL alarm triggered\n");
}

int main() {
    struct itimerval t;
    signal(SIGALRM, handler);
    t.it_interval.tv_sec = 10;
    t.it_interval.tv_usec = 10;
    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 10;
    setitimer(ITIMER_REAL, &t, NULL);
    while (1) pause();
    return 0;
}

/*
======================================================================================
output:
aman-tiwari@aman-tiwari:~/Hands_on_list2$ vim 1a.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ cc 1a.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./a.out
ITIMER_REAL alarm triggered
ITIMER_REAL alarm triggered
ITIMER_REAL alarm triggered
ITIMER_REAL alarm triggered
ITIMER_REAL alarm triggered
ITIMER_REAL alarm triggered
ITIMER_REAL alarm triggered
ITIMER_REAL alarm triggered
ITIMER_REAL alarm triggered
ITIMER_REAL alarm triggered
ITIMER_REAL alarm triggered
ITIMER_REAL alarm triggered
ITIMER_REAL alarm triggered
ITIMER_REAL alarm triggered
ITIMER_REAL alarm triggered

======================================================================================
*/
