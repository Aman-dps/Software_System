/*
======================================================================================
Name        : 6.c
Author      : Aman Tiwari
Description : Program to demonstrate creation of three threads using POSIX pthreads.
======================================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
    int id = *(int*)arg;
    printf("Greetings from thread %d (TID: %lu)\n", id, pthread_self());
    return NULL;
}

int main() {
    pthread_t th1, th2, th3;
    int x = 1, y = 2, z = 3;

    // Create three threads
    pthread_create(&th1, NULL, thread_func, &x);
    pthread_create(&th2, NULL, thread_func, &y);
    pthread_create(&th3, NULL, thread_func, &z);

    // Wait for all threads to finish
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 06.c -o 06 -lpthread
(base) amantiwari@Amans-MacBook-Air list2 % ./06
Greetings from thread 1 (TID: 123145552814080)
Greetings from thread 2 (TID: 123145559678976)
Greetings from thread 3 (TID: 123145566543872)

======================================================================================
*/
