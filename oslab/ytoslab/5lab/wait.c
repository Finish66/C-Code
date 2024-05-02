#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
	pid_t pid;
	int status;
	pid = fork();

	if(pid == 0){
		// Child 
		printf("Child running\n");
		sleep(2);
		printf("Child exiting\n");
		exit(0);
	} else {
		printf("Parent wating for child...\n");
		wait(&status);
		printf("Child process exited with %d\n",status);
	}
	return 0;
}

