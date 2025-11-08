/*
======================================================================================
Name        : 32b.c
Author      : Aman Tiwari
Description : 
Write a program to implement semaphore to protect any critical section.
a. Rewrite the ticket number creation program using semaphore
b. Protect shared memory from concurrent write access
c. Protect multiple pseudo resources (may be two) using counting semaphore
d. Remove the created semaphore
======================================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

sem_t sem;
char shared[100];

void* writer(void* arg) {
    sem_wait(&sem);  // Enter critical section
    sprintf(shared, "Written by Thread %ld", (long)arg);
    printf("%s\n", shared);
    sem_post(&sem);  // Exit critical section
    return NULL;
}

int main() {
    pthread_t t[3];

    sem_init(&sem, 0, 1);  // Initialize binary semaphore

    for (int i = 0; i < 3; i++)
        pthread_create(&t[i], NULL, writer, (void*)(long)(i + 1));

    for (int i = 0; i < 3; i++)
        pthread_join(t[i], NULL);

    sem_destroy(&sem);  // Remove semaphore
    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/32$ gcc 32b.c -o b
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/32$ ./b
Written by Thread 1
Written by Thread 2
Written by Thread 3
======================================================================================
*/
