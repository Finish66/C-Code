//Process Management

//Q2. Write a program using system calls for operations on processes to create a heirarchy of processes P1 -> P2 -> P3, also print the id and parent id for each process

#include<stdio.h>             //  for printf and scanf 
#include<unistd.h>            //  for fork(), getpid() & getppid() 
#include<sys/types.h>         //  for fork(), getpid() & getppid() 
#include <stdlib.h>           //  for exit() 

int main()
{
	printf("Parent PID : %d \n", (int) getpid());
	
	pid_t pid = fork();
	
	if(pid == 0)
	{
		printf("Child 1 PID : %d Parent PID : %d\n", (int) getpid(), (int) getppid());
		pid_t pid_1 = fork();
		if(pid_1 == 0)
		{
			printf("Child 2 PID : %d Parent PID (Child 1) : %d \n", (int) getpid(), (int) getppid());
			exit(0);
		}
		else
		{
			exit(0);
		}
	}
	else
	{
		exit(0);	
	}
	
	return 0;
}
