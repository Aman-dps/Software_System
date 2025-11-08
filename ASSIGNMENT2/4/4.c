/*
======================================================================================
Name        : 04
Author      : Aman Tiwari
Description : Program to measure time taken for 100 getppid() system calls using RDTSC
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <x86intrin.h>

int main() {
    unsigned long long start, end;
    int i;

    start = __rdtsc();

    for (i = 0; i < 100; i++) {
        getppid();
    }

    end = __rdtsc();

    printf("CPU cycles taken for 100 getppid() calls: %llu\n", end - start);

    return 0;
}

/*
======================================================================================
output:
aman-tiwari@aman-tiwari:~/Hands_on_list2$ vim 4.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ cc 4.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./a.out
CPU cycles taken for 100 getppid() calls: 136494

======================================================================================
*/
