/*
======================================================================================
Name        : 06
Author      : Aman Tiwari
Description : Simple program to create three threads using pthreads
======================================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* mythread(void* arg) {
    int n = *(int*)arg;
    printf("Hello from thread %d\n", n);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    int a = 1, b = 2, c = 3;
    pthread_create(&t1, NULL, mythread, &a);
    pthread_create(&t2, NULL, mythread, &b);
    pthread_create(&t3, NULL, mythread, &c);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}

/*
======================================================================================
OUTPUT:
aman-tiwari@aman-tiwari:~$ cd Hands_on_list2
aman-tiwari@aman-tiwari:~/Hands_on_list2$ cc 6.c
aman-tiwari@aman-tiwari:~/Hands_on_list2$ ./a.out
Hello from thread 2
Hello from thread 1
Hello from thread 3
aman-tiwari@aman-tiwari:~/Hands_on_list2$ 

======================================================================================
*/
