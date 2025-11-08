/*
======================================================================================
Name        : 12
Author      : Aman Tiwari
Description : Program to create an orphan process. Child sends SIGKILL to its parent.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child process (PID: %d) sending SIGKILL to parent (PID: %d)\n", getpid(), getppid());
        kill(getppid(), SIGKILL);
        sleep(2);
        printf("Child process (PID: %d) new parent PID: %d \n", getpid(), getppid());
    } else {
        while (1) {
            printf("Parent process (PID: %d) running...\n", getpid());
            sleep(1);
        }
    }

    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari:~/Hands_on_list2$ vim 12.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ cc 12.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./a.out
Parent process (PID: 17577) running...
Child process (PID: 17578) sending SIGKILL to parent (PID: 17577)
Killed
aman-tiwari@aman-tiwari:~/Hands_on_list2$ Child process (PID: 17578) new parent PID: 1999 
^C

======================================================================================
*/
