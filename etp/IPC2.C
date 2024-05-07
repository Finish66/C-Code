//Establish Interprocess communication (IPC) between Parent and child process using named pipe.

#include <sys/types.h> 
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){

	int pid, fd1, fd2;
	char buffer[20];
	
	mkfifo("my_Pipe", 0666); 
	
	pid=fork();
	if(pid > 0){
		//Parent Section
		fd1=open("my_Pipe", O_WRONLY); 
		write(fd1, "Hello Child Process\n",20);
	}
	if(pid==0){
		//Child section
		fd2=open("my_Pipe", O_RDONLY);
		read(fd2, buffer, 20);
		printf("%s", buffer);
	}
	
	return 0;
}
