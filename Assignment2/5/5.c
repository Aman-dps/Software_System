/*
======================================================================================
Name        : 05.c
Author      : Aman Tiwari
Description : Program to display important system configuration limits using sysconf()
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("ARG_MAX (max length of arguments to exec): %ld\n", sysconf(_SC_ARG_MAX));
    printf("CHILD_MAX (max processes per user ID): %ld\n", sysconf(_SC_CHILD_MAX));
    printf("CLK_TCK (clock ticks per second): %ld\n", sysconf(_SC_CLK_TCK));
    printf("OPEN_MAX (max number of open files): %ld\n", sysconf(_SC_OPEN_MAX));
    printf("PAGESIZE (page size in bytes): %ld\n", sysconf(_SC_PAGESIZE));
    printf("PHYS_PAGES (total physical memory pages): %ld\n", sysconf(_SC_PHYS_PAGES));
    printf("AVPHYS_PAGES (available physical memory pages): %ld\n", sysconf(_SC_AVPHYS_PAGES));

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 05.c
(base) amantiwari@Amans-MacBook-Air list2 % ./a.out
ARG_MAX (max length of arguments to exec): 262144
CHILD_MAX (max processes per user ID): 709
CLK_TCK (clock ticks per second): 100
OPEN_MAX (max number of open files): 1048575
PAGESIZE (page size in bytes): 16384
PHYS_PAGES (total physical memory pages): 2621440
AVPHYS_PAGES (available physical memory pages): 1734560
======================================================================================
*/
