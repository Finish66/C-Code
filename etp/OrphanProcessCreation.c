//C program to demonstrates the creation of an orphan process:

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid == 0) {
        // Child process
        printf("Child process : PID = %d\n", getpid());
        sleep(2); // Sleep to ensure the parent process terminates first
        printf("Child process : My parent's PID = %d\n", getppid());
    } else if (child_pid > 0) {
        // Parent process
        printf("Parent process : PID = %d\n", getpid());
        printf("Parent process : Terminating . . . \n");
    } else {
        printf("Fork failed\n");
        return 1;
    }

    return 0;
}
