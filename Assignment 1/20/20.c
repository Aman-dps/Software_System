/*
===========================================================================================================================
Name : 20.c
Author : Aman Tiwari
Description :Find out the priority of your running program. Modify the priority with nice command.
===========================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
	int p=10;
	pid_t pid=getpid();
	printf("PId = %d\n",pid);
	p=getpriority(PRIO_PROCESS,0); // 0 : current process
	printf("Before changing:\n");
	printf("Current priority : %d\n",p);

}
/*
=====OUTPUT================================================================================================================
(base) amantiwari@Amans-MacBook-Air 20 % gcc 20.c
(base) amantiwari@Amans-MacBook-Air 20 % ./a.out 
PId = 35651
Before changing:
Current priority : 0
(base) amantiwari@Amans-MacBook-Air 20 % nice -n 10 ./a.out
PId = 35809
Before changing:
Current priority : 10
===========================================================================================================================
*/
