//A program to create a child process using fork system call:

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid == 0) {
        // The child process code section
        printf("Child process : PID = %d\n", getpid());
    } else if (child_pid > 0) {
        // The parent process code section
        printf("Parent process : Child PID = %d\n", child_pid);
    } else {
        // Fork failed
        printf("Fork failed\n");
        return 1;
    }

    return 0;
}
