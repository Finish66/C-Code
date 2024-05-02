#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
	pid_t pid = getpid();
	printf("Current: %d\n", pid);
	printf("Forking...\n");
	pid_t childPid = fork();

	if(childPid == -1) {
		printf("Failed to fork\n");
		return 1;
	} else if (childPid == 0) {
		printf("Parent: %d, Child: %d\n",getppid(),getpid());
	} else {
		printf("Parent: %d\n",getppid());
	}
}
