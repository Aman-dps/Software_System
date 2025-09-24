/*
===========================================================================================================================
Name : 27_c.c
Author : Aman Tiwari
Description :Write a program to execute ls -Rl by the following system calls
c. execle

===========================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Running ls -Rl using execle...\n");

    char *envp[] = { "PATH=/bin:/usr/bin", NULL };  // custom environment

    execle("/bin/ls", "ls", "-Rl", NULL, envp);

    perror("execle failed");
    return 1;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air Assignment 1 % gcc 27_c.c
(base) amantiwari@Amans-MacBook-Air Assignment 1 % ./a.out   
Running ls -Rl using execle...
total 368
-rw-r--r--@ 1 amantiwari  admin   1158 Sep  1 15:55 11_filedescriptor-duplicate.cpp
-rw-r--r--@ 1 amantiwari  admin    519 Sep  1 17:33 12_opening_mode.cpp
-rw-r--r--@ 1 amantiwari  admin    589 Sep  1 17:39 13_wait_select.cpp
-rw-r--r--@ 1 amantiwari  admin   1013 Sep  1 17:45 14_filetype.cpp
-rw-r--r--@ 1 amantiwari  admin    303 Sep  1 17:56 15_env_variables.cpp
-rw-r--r--@ 1 amantiwari  admin    558 Sep  1 18:21 16_readlock.c
-rw-r--r--@ 1 amantiwari  admin    571 Aug 14 15:45 16_writelock.c
-rw-r--r--@ 1 amantiwari  admin    365 Sep  2 19:48 17-initializetickete.c
-rw-r--r--@ 1 amantiwari  admin    964 Sep  2 20:16 17-reserve_ticket.c
drwxr-xr-x  4 amantiwari  admin    128 Sep  4 15:03 19
-rw-r--r--@ 1 amantiwari  admin    209 Aug 24 14:14 1a_softlink.c
-rw-r--r--@ 1 amantiwari  admin    206 Aug 24 14:42 1b_hardlink.c
-rw-r--r--@ 1 amantiwari  admin    219 Aug 24 16:37 1c_fifo_file.c
drwxr-xr-x  4 amantiwari  admin    128 Sep  4 15:12 20
-rw-r--r--@ 1 amantiwari  admin   1164 Sep  6 09:40 21.c
-rw-r--r--@ 1 amantiwari  admin   1469 Sep  6 09:47 22.c
-rw-r--r--@ 1 amantiwari  admin   1363 Sep  6 09:49 23.c
-rw-r--r--@ 1 amantiwari  admin   1418 Sep  6 09:53 24.c
-rw-r--r--@ 1 amantiwari  admin   1730 Sep  6 10:03 25.c
-rw-r--r--@ 1 amantiwari  admin    999 Sep  6 10:37 26_a.c
-rw-r--r--@ 1 amantiwari  admin   1156 Sep  6 10:37 26_b.c
-rw-r--r--@ 1 amantiwari  admin   3395 Sep  6 11:05 27_a.c
-rw-r--r--@ 1 amantiwari  admin   3330 Sep  6 11:26 27_b.c
-rw-r--r--@ 1 amantiwari  admin   1002 Sep  6 11:32 27_c.c
-rw-r--r--@ 1 amantiwari  admin    296 Aug 24 22:52 3_file_descriptor.c
-rw-r--r--@ 1 amantiwari  admin    530 Aug 25 18:49 4_read-write_mode.c
-rw-r--r--@ 1 amantiwari  admin    356 Aug 25 20:52 6_read-write_file.c
-rw-r--r--@ 1 amantiwari  admin    454 Aug 28 22:17 7_copyfile.c
-rw-r--r--@ 1 amantiwari  admin    612 Aug 31 23:18 9_file-stat.cpp
-rwxr-xr-x  1 amantiwari  admin  33656 Sep  6 11:32 a.out
-rwxr-xr-x  1 amantiwari  admin  33432 Sep  6 10:35 hello
-rw-r--r--@ 1 amantiwari  admin     35 Sep  6 09:41 output.txt

./19:
total 40
-rw-r--r--@ 1 amantiwari  admin    477 Sep  4 14:51 19_timebyprocess.c
-rwxrwxr-x@ 1 amantiwari  admin  16040 Aug 24 19:36 a.out

./20:
total 80
-rw-r--r--@ 1 amantiwari  admin    153 Sep  4 15:12 20.c
-rwxr-xr-x  1 amantiwari  admin  33512 Sep  4 15:12 a.out
===========================================================================================================================
*/