/*
======================================================================================
Name        : 09
Author      : Aman Tiwari
Description : Program to ignore SIGINT first, then reset it to default action
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Ignoring SIGINT for 10 seconds. Try pressing Ctrl+C...\n");
    signal(SIGINT, SIG_IGN);
    sleep(10);

    printf("Now resetting SIGINT to default. Press Ctrl+C to terminate.\n");
    signal(SIGINT, SIG_DFL);

    while (1) {
        sleep(1);
    }

    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari:~/Hands_on_list2$ vim 9.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ cc 9.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./a.out
Ignoring SIGINT for 10 seconds. Try pressing Ctrl+C...
^C^C^CNow resetting SIGINT to default. Press Ctrl+C to terminate.
^C
aman-tiwari@aman-tiwari:~/Hands_on_list2$ 

======================================================================================
*/
