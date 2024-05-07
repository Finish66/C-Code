//C program to demonstrate the creation of a Zombie process:


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid == 0) {
        // Child process
        printf("Child process : PID = %d\n", getpid());
        exit(0); // Child process exits immediately
    } else if (child_pid > 0) {
        // Parent process
        printf("Parent process : PID = %d\n", getpid());
        printf("Parent process : Child PID = %d\n", child_pid);
        sleep(10); // Sleep to allow time for the child to become a zombie
        printf("Parent process : Terminating . . . \n");
    } else {
        printf("Fork failed\n");
        return 1;
    }

    return 0;
}
