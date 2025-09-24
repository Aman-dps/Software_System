/*
===========================================================================================================================
Name : 6.c
Author : Aman Tiwari
Description :Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
===========================================================================================================================
*/
#include <unistd.h>   // For read(), write()

int main() {
    char buffer[100];       // storage for input
    int n;

    // read up to 100 characters from STDIN (file descriptor 0)
    n = read(0, buffer, sizeof(buffer));

    if (n > 0) {
        // write the same data to STDOUT (file descriptor 1)
        write(1, buffer, n);
    }

    return 0;
}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 6 % gcc 6_read-write_file.c 
(base) amantiwari@Amans-MacBook-Air 6 % ./a.out                
hello everyone this is 6th question
hello everyone this is 6th question
===========================================================================================================================
*/
