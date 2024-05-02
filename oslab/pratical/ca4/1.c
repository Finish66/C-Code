#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];

    pipe(pipefd);
    pid = fork();

    if (pid == 0) {
        close(pipefd[0]);
        char message[] = "Hello, Parent Process!";
        write(pipefd[1], message, sizeof(message));
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    } else {
        close(pipefd[1]);
        read(pipefd[0], buffer, BUFFER_SIZE);
        printf("Message received from child process: %s\n", buffer);
        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    }

    return 0;
}
