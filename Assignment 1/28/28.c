/*
===========================================================================================================================
Name : 28.c
Author : Aman Tiwari
Description :Write a program to get maximum and minimum real time priority.
===========================================================================================================================
*/
#include <stdio.h>
#include <sched.h>

int main() {
    int min, max;

    min = sched_get_priority_min(SCHED_FIFO);
    max = sched_get_priority_max(SCHED_FIFO);
    printf("SCHED_FIFO: Min = %d, Max = %d\n", min, max);

    min = sched_get_priority_min(SCHED_RR);
    max = sched_get_priority_max(SCHED_RR);
    printf("SCHED_RR  : Min = %d, Max = %d\n", min, max);

    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air Assignment 1 % gcc 28.c  
(base) amantiwari@Amans-MacBook-Air Assignment 1 % ./a.out   
SCHED_FIFO: Min = 15, Max = 47
SCHED_RR  : Min = 15, Max = 47
===========================================================================================================================
*/
