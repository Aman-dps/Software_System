/*
======================================================================================
Name        : 08d_sigalrm.c
Author      : Aman Tiwari
Description : Program to demonstrate handling of SIGALRM using the alarm() system call.
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>  
#include <unistd.h>   

void alarm_handler(int signo) {
    printf("Signal handler: Caught SIGALRM (Alarm signal triggered)\n");
    exit(EXIT_SUCCESS);
}

int main() {
    // Register handler for SIGALRM
    signal(SIGALRM, alarm_handler);

    printf("Setting an alarm to go off in 5 seconds...\n");
    alarm(5);         // Schedule alarm
    pause();          // Wait for signal

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 08d_sigalrm.c -o 08d_sigalrm
(base) amantiwari@Amans-MacBook-Air list2 % ./08d_sigalrm
Setting an alarm to go off in 5 seconds...
Signal handler: Caught SIGALRM (Alarm signal triggered)

======================================================================================
*/
