/*
===========================================================================================================================
Name : 3.c
Author : Aman Tiwari
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>

int main() {
    struct rlimit limit;

    // Get current limit
    if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("getrlimit");
        exit(1);
    }

    printf("Before change:\n");
    printf("Open files -> Soft limit: %llu, Hard limit: %llu\n",
           (unsigned long long)limit.rlim_cur,
           (unsigned long long)limit.rlim_max);

    // Set new limit (soft limit = 50, keep hard limit same)
    limit.rlim_cur = 50;

    if (setrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("setrlimit");
        exit(1);
    }

    // Get again to verify
    if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("getrlimit");
        exit(1);
    }

    printf("\nAfter change:\n");
    printf("Open files -> Soft limit: %llu, Hard limit: %llu\n",
           (unsigned long long)limit.rlim_cur,
           (unsigned long long)limit.rlim_max);

    return 0;
}


/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 3 % gcc 3.c                                                     
(base) amantiwari@Amans-MacBook-Air 3 % ./a.out                                                     
Before change:
Open files -> Soft limit: 1048575, Hard limit: 9223372036854775807

After change:
Open files -> Soft limit: 50, Hard limit: 9223372036854775807
===========================================================================================================================
*/