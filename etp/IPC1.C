//Establish Interprocess communication (IPC) between Parent and child process using unnamed pipe.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	int pipefd[2]; // file descriptors for the pipe
	char buffer[25];
	pid_t pid;

	if (pipe(pipefd) == -1) { // create the pipe
    	printf("Pipe failed\n");
    	return 1;
	}

	pid = fork(); // create a child process

	if (pid < 0) { // fork failed
    	printf("Fork failed\n");
    	return 1;
	}

	if (pid > 0) { // parent process
    	close(pipefd[0]); // close the read end of the pipe
    	printf("Parent process writing to pipe...\n");
    	write(pipefd[1], "Hello, child process!", 22);
    	close(pipefd[1]); // close the write end of the pipe
	}
	else { // child process
    	close(pipefd[1]); // close the write end of the pipe
    	printf("Child process reading from pipe...\n");
    	read(pipefd[0], buffer, 25);
    	printf("Child process received: %s\n", buffer);
    	close(pipefd[0]); // close the read end of the pipe
	}

	return 0;
}
