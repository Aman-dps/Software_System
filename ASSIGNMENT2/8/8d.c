/*
======================================================================================
Name        : 08d
Author      : Aman Tiwari
Description : Program to catch SIGALRM using alarm() system call
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>  
#include <unistd.h>   

void handler(int s) {
    printf("Caught signal SIGALRM: Alarm signal received!\n");
    exit(0);
}

int main() {
    signal(SIGALRM, handler);
    printf("Setting alarm for 5 seconds...\n");
    alarm(5);        
    pause();      
    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari:~/Hands_on_list2$ vim 8d.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ cc 8d.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./a.out
Setting alarm for 5 seconds...
Caught signal SIGALRM: Alarm signal received!
aman-tiwari@aman-tiwari:~/Hands_on_list2$ 

======================================================================================
*/
