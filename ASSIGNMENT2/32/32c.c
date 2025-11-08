/*
========================================================================
Name        : 32c.c
Author      : AMAN TIWARI
Description : 
Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources (may be two) using counting semaphore
d. remove the created semaphore
========================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void* access_resource(void* arg) {
    printf("Thread %ld waiting\n", (long)arg);
    sem_wait(&sem);
    printf("Thread %ld using resource\n", (long)arg);
    sleep(2);
    printf("Thread %ld done\n", (long)arg);
    sem_post(&sem);
    return NULL;
}

int main() {
    pthread_t t[5];
    sem_init(&sem, 0, 2);
    for (int i = 0; i < 5; i++) pthread_create(&t[i], NULL, access_resource, (void*)(long)(i+1));
    for (int i = 0; i < 5; i++) pthread_join(t[i], NULL);
    sem_destroy(&sem);
    return 0;
}

/*
========================================================================
SIGNMENT2/32$ gcc 32c.c -o c
aman-tiwari@aman-tiwari-Nitro-AN515-52:~/Documents/ASSIGNMENT2/32$ ./c
Thread 1 waiting
Thread 1 using resource
Thread 2 waiting
Thread 2 using resource
Thread 3 waiting
Thread 5 waiting
Thread 4 waiting
Thread 2 done
Thread 1 done
Thread 3 using resource
Thread 5 using resource
Thread 5 done
Thread 3 done
Thread 4 using resource
Thread 4 done
========================================================================
*/
