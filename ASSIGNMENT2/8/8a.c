/*
======================================================================================
Name        : 08a_sigsegv
Author      : Aman Tiwari
Description : Program to catch segmentation fault (SIGSEGV)
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>   

void handler(int s) {
    printf("Caught signal SIGSEGV: Segmentation Fault\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, handler);
    int *p = NULL;
    *p = 10;   
    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari:~/Hands_on_list2$ cc 8a.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./a.out
Caught signal SIGSEGV: Segmentation Fault
 


======================================================================================
*/
