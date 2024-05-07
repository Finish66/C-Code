//Exercise 2: Write a C program utilizing the fork() system call to generate the following process hierarchy: P1 → P2 → P3. The program should display the Process ID (PID) and Parent Process IDs (PPID) for each process created.

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 == 0) {
        printf("P2: PID = %d, PPID = %d\n", getpid(), getppid());
        pid2 = fork();

        if (pid2 == 0) {
            printf("P3: PID = %d, PPID = %d\n", getpid(), getppid());
        }
    } else {
        printf("P1: PID = %d, PPID = %d\n", getpid(), getppid());
    }

    return 0;
}
