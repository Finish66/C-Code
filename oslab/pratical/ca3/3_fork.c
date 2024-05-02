#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 == 0) {
        printf("child P1 = PID: %d PPID: %d\n", getpid(), getppid());
    } else if (pid1 > 0) {
        pid2 = fork();

        if (pid2 == 0) {
        printf("child P1 = PID: %d PPID: %d\n", getpid(), getppid());
        } else if (pid2 > 0) {
            printf("Parent P = PID: %d created P1 PID: %d and P2 PID: %d\n", getpid(), pid1, pid2);
        } else {
            printf("Error P2\n");
            return 1;
        }
    } else {
        printf("Error creating child process P1\n");
        return 1;
    }

    return 0;
}
