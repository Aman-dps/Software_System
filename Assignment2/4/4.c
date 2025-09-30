/*
======================================================================================
Name        : 04.c
Author      : Aman Tiwari
Description : Program to calculate the number of CPU cycles consumed by executing
              100 getppid() system calls using the RDTSC instruction.
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <immintrin.h>   // for __rdtsc()

int main() {
    unsigned long long t_start, t_end;
    int count;

    // Record timestamp counter before loop
    t_start = __rdtsc();

    for (count = 0; count < 100; count++) {
        getppid();
    }

    // Record timestamp counter after loop
    t_end = __rdtsc();

    printf("CPU cycles used for 100 getppid() calls: %llu\n", t_end - t_start);

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 04.c
(base) amantiwari@Amans-MacBook-Air list2 % ./a.out
CPU cycles used for 100 getppid() calls: 142876

======================================================================================
*/
