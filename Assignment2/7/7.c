/*
======================================================================================
Name        : 07.c
Author      : Aman Tiwari
Description : Program to spawn multiple threads and display their unique thread IDs.
======================================================================================
*/

#include <stdio.h>
#include <pthread.h>

void* thread_job(void* arg) {
    printf("Thread running with ID: %lu\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t thr1, thr2, thr3;

    // Create three threads
    pthread_create(&thr1, NULL, thread_job, NULL);
    pthread_create(&thr2, NULL, thread_job, NULL);
    pthread_create(&thr3, NULL, thread_job, NULL);

    // Wait for completion of threads
    pthread_join(thr1, NULL);
    pthread_join(thr2, NULL);
    pthread_join(thr3, NULL);

    return 0;
}

/*
======================================================================================
Output:
(base) amantiwari@Amans-MacBook-Air list2 % gcc 07.c -o 07 -lpthread
(base) amantiwari@Amans-MacBook-Air list2 % ./07
Thread running with ID: 123145556611072
Thread running with ID: 123145563475968
Thread running with ID: 123145570340864

======================================================================================
*/
