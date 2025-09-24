/*
===========================================================================================================================
Name : 29.c
Author : Aman Tiwari
Description :Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
===========================================================================================================================
*/
#include <stdio.h>
#include <sched.h>
#include <unistd.h>

int main() {
    int policy;
    struct sched_param param;

   
    policy = sched_getscheduler(0);
    if (policy == SCHED_OTHER)
        printf("Current Policy: SCHED_OTHER\n");
    else if (policy == SCHED_FIFO)
        printf("Current Policy: SCHED_FIFO\n");
    else if (policy == SCHED _RR)
        printf("Current Policy: SCHED_RR\n");

    // Set new policy (example: SCHED_FIFO with priority 10)
    param.sched_priority = 10;
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("Failed to set policy");
    } else {
        printf("Policy changed to SCHED_FIFO with priority 10\n");
    }

    return 0;
}
/*
=====OUTPUT================================================================================================================
Current policy : 0
New priority: 10
===========================================================================================================================
*/
