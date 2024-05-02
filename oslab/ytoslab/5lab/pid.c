#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	printf("Process: %d\n", getpid());
	pid = fork();

	if(pid == 0)
		printf("Child: %d->%d\n", getpid(),getppid());
	else
		printf("Parent: %d->%d\n", getpid(),getppid());
	return 0;
}
