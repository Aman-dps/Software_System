/*
===========================================================================================================================
Name : 2.c
Author : Aman Tiwari
Description :Write a program to print the system resource limits. Use getrlimit system call.
===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>

void print_limit(int resource, const char *name) {
    struct rlimit limit;
    if (getrlimit(resource, &limit) == 0) {
        printf("%-15s -> Soft limit: ", name);

        if (limit.rlim_cur == RLIM_INFINITY)
            printf("INFINITY");
        else
            printf("%llu", (unsigned long long)limit.rlim_cur);

        printf(", Hard limit: ");
        if (limit.rlim_max == RLIM_INFINITY)
            printf("INFINITY\n");
        else
            printf("%llu\n", (unsigned long long)limit.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main() {
    printf("System Resource Limits:\n\n");

    print_limit(RLIMIT_CPU, "CPU time");
    print_limit(RLIMIT_FSIZE, "File size");
    print_limit(RLIMIT_DATA, "Data seg size");
    print_limit(RLIMIT_STACK, "Stack size");
    print_limit(RLIMIT_CORE, "Core file size");
    print_limit(RLIMIT_RSS, "Resident set");       // optional
    print_limit(RLIMIT_NOFILE, "Open files");
    print_limit(RLIMIT_AS, "Address space");
#ifdef RLIMIT_NPROC
    print_limit(RLIMIT_NPROC, "Processes");
#endif
#ifdef RLIMIT_MEMLOCK
    print_limit(RLIMIT_MEMLOCK, "Locked memory");
#endif

    return 0;
}



/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 2 % gcc 2.c 
(base) amantiwari@Amans-MacBook-Air 2 % ./a.out
System Resource Limits:

CPU time        -> Soft limit: INFINITY, Hard limit: INFINITY
File size       -> Soft limit: INFINITY, Hard limit: INFINITY
Data seg size   -> Soft limit: INFINITY, Hard limit: INFINITY
Stack size      -> Soft limit: 8372224, Hard limit: 67092480
Core file size  -> Soft limit: 0, Hard limit: INFINITY
Resident set    -> Soft limit: INFINITY, Hard limit: INFINITY
Open files      -> Soft limit: 1048575, Hard limit: INFINITY
Address space   -> Soft limit: INFINITY, Hard limit: INFINITY
Processes       -> Soft limit: 1333, Hard limit: 2000
Locked memory   -> Soft limit: INFINITY, Hard limit: INFINITY
===========================================================================================================================
*/