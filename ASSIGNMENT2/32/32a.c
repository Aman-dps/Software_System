/*
======================================================================================
Name        : 32a.c
Author      : Aman Tiwari
Description : 
Write a program to implement semaphore to protect any critical section.
a. Rewrite the ticket number creation program using semaphore
b. Protect shared memory from concurrent write access
c. Protect multiple pseudo resources (may be two) using counting semaphore

======================================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;
int ticket = 0;

void* get_ticket(void* arg) {
    sem_wait(&sem);  // Enter critical section
    ticket++;
    printf("Thread %ld got ticket %d\n", (long)arg, ticket);
    sem_post(&sem);  // Exit critical section
    return NULL;
}

int main() {
    pthread_t t[5];
    sem_init(&sem, 0, 1);  // Initialize semaphore (binary)

    for (int i = 0; i < 5; i++)
        pthread_create(&t[i], NULL, get_ticket, (void*)(long)(i + 1));

    for (int i = 0; i < 5; i++)
        pthread_join(t[i], NULL);

    sem_destroy(&sem);  // Remove semaphore
    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/32$ gcc 32a.c -o a
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/32$ ./a
Thread 1 got ticket 1
Thread 4 got ticket 2
Thread 2 got ticket 3
Thread 5 got ticket 4
Thread 3 got ticket 5
======================================================================================
*/
