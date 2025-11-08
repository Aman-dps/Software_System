/*
======================================================================================
Name        : 03
Author      : Aman Tiwari
Description : Program to set system resource limit using setrlimit system call
======================================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit l;
    getrlimit(RLIMIT_NOFILE, &l);
    printf("Before: Soft=%ld Hard=%ld\n", (long)l.rlim_cur, (long)l.rlim_max);
    l.rlim_cur = 512;
    l.rlim_max = 1024;
    setrlimit(RLIMIT_NOFILE, &l);
    getrlimit(RLIMIT_NOFILE, &l);
    printf("After : Soft=%ld Hard=%ld\n", (long)l.rlim_cur, (long)l.rlim_max);

    return 0;
}

/*
======================================================================================
output:
aman-tiwari@aman-tiwari:~/Hands_on_list2$ vim 3.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ cc 3.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./a.out
Before: Soft=1024 Hard=1048576
After : Soft=512 Hard=1024
aman-tiwari@aman-tiwari:~/Hands_on_list2$ 

======================================================================================
*/
