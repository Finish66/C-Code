#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/types.h>


int main(){
	pid_t pid;
	pid = fork();

	if(pid > 0){
		printf("Parent sleeping\n");
		wait(NULL);	
		sleep(20);
		printf("Parent PID: %d\n",getpid());
	}else if(pid == 0){
		printf("Child PID: %d\n",getppid());
		exit(0);
	}else{
		printf("Failed\n");
		exit(1);
	}
	return 0;
}

