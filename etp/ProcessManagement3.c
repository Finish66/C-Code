//Process Management 

//Q3. Write a program using system calls for operations on processes to create a heirarchy of processes: P3 <- P2 <- P1 -> P4 -> P5, also stimulate process P4 as orphan and P5 as zombie




#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	printf("P1 PID : %d \n", (int) getpid());
	pid_t pid = fork();

	if(pid == 0)
	{
		printf("P4 PID : %d P1 PID : %d\n", (int) getpid(), (int) getppid());
		printf("Child process P4 is sleeping \n");
		pid_t pid_1 = fork();
		sleep(5);
		if(pid_1 == 0)
		{
			printf("P5 PID : %d P4 PID : %d \n", (int) getpid(), (int) getppid());
			printf("Zombie process P5's PID : %d \n", (int) getpid());
		}
		else{
			printf("Orphan child process P4's PID : %d \n", (int) getpid());
			printf("P4's New Parent PID : %d \n", (int) getppid());
		}
	}
	else
	{
		pid = fork();
		if(pid == 0)
		{
			printf("P2 PID : %d P1 PID : %d\n", (int) getpid(), (int) getppid());
			pid_t pid_1 = fork();
			if(pid_1 == 0)
			{
				printf("P3 PID : %d P2 PID : %d \n", (int) getpid(), (int) getppid());
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
	}

	return 0;
}
