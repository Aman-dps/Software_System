/*
===========================================================================================================================
Name : 30.c
Author : Aman Tiwari
Description :Write a program to run a script at a specific time using a Daemon process.
===========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void create_daemon() {
    pid_t pid;

    // First fork
    pid = fork();
    if (pid < 0) exit(1);
    if (pid > 0) exit(0); // parent exits

    // Create session Child becomes daemon
    if (setsid() < 0) exit(1);

    ` // Second fork
    pid = fork();
     if (pid < 0) exit(1);
     if (pid > 0) exit(0);

    // Change working directory
    chdir("/");

    // Set permissions
    umask(0); //The umask is set to 0. This is to ensure that any files the daemon creates will have the permissions the program explicitly specifies, without any default permission bits being turned off.

    // Close standard fds
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

int main() {
    create_daemon();

    int target_hour = 9;   
    int target_min  = 52;

    while (1) {
        time_t now = time(NULL);
        struct tm *tm_now = localtime(&now);

         if (tm_now->tm_hour == target_hour && tm_now->tm_min == target_min) {
         /*   execl("/bin/sh", "sh", "/path/to/myscript.sh", (char *)NULL);
            exit(1); // if execl fails*/
            system("./myscript.sh");
            sleep(60);
        }	
        sleep(30); // check every 30 seconds
    }

    return 0;
}
/*
=====OUTPUT================================================================================================================
At 14:30 the script will run automatically as a daemon.

Example (myscript.sh):
------------------------------------
#!/bin/bash
echo "Script ran at $(date)" >> /home/user/output.txt
------------------------------------

Output file (output.txt) after 14:30:
------------------------------------
Script ran at Thu Sep  4 14:30:00 IST 2025
===========================================================================================================================
*/
