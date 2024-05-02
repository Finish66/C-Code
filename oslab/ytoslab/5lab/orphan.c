#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

	pid_t childId = fork();
	
	if(childId > 0){
		printf("Parent... PID: %d\n",getpid());
	} 
	else if(childId == 0){
		printf("Child before PID: %d PPID: %d\n",getpid(),getppid());
		sleep(10);
		printf("Child after PID: %d PPID: %d\n",getpid(),getppid());
	}
	else{
		printf("Error!!\n");
	}
}
