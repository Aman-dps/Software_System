/*
======================================================================================
Name        : 12_orphan_process.c
Author      : Aman Tiwari
Description : Program to demonstrate an orphan process. 
              The child sends SIGKILL to its parent, making itself an orphan 
              (later adopted by init/systemd).
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    setbuf(stdout, NULL);  // disable output buffering for clean logs

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {  
        // Child process
        printf(" Child process started (PID: %d), Parent PID: %d\n", getpid(), getppid());
        sleep(1);

        // Kill parent
        kill(getppid(), SIGKILL);
        printf(" Child sent SIGKILL to parent.\n");

        // Wait a little so adoption happens
        sleep(2);
        printf(" Child process (PID: %d) is now orphan, adopted by init/systemd. New Parent PID: %d\n", 
               getpid(), getppid());

        while (1) sleep(1);  // keep child alive
    } 
    else {  
        // Parent process
        printf(" Parent process running (PID: %d). Waiting...\n", getpid());
        while (1) sleep(1);  // parent will be killed by child
    }

    return 0;
}

/*
======================================================================================
Sample Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 12_orphan_process.c -o 12_orphan_process
(base) amantiwari@Amans-MacBook-Air list2 % ./12_orphan_process
 Parent process running (PID: 4812). Waiting...
 Child process started (PID: 4813), Parent PID: 4812
 Child sent SIGKILL to parent.
Killed
 Child process (PID: 4813) is now orphan, adopted by init/systemd. New Parent PID: 1

======================================================================================
*/
