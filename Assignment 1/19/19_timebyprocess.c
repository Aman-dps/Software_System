/*
===========================================================================================================================
Name : 19.c
Author : Aman Tiwari
Description :Write a program to find out time taken to execute getpid system call. Use time stamp counter.
===========================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <mach/mach_time.h>

int main() {
    uint64_t start, end;
    pid_t pid;

    start = mach_absolute_time();
    pid = getpid();
    end = mach_absolute_time();

    printf("PID = %d\n", pid);
    printf("getpid() took %llu ns (approx)\n",
           (unsigned long long)(end - start));

    return 0;
}


/*Output: 
PID = 87691
getpid() took 1 ns (approx)
*/
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 19 % gcc 19_timebyprocess.c
(base) amantiwari@Amans-MacBook-Air 19 % ./a.out               
PID = 36952
getpid() took 1 ns (approx)
===========================================================================================================================
*/