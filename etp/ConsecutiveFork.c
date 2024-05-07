//Exercise 1: Write a C program to illustrate that performing 'n' consecutive fork() system calls generates a total of 2n − 1 child processes. The program should prompt the user to input the value of 'n'.

#include <stdio.h>
#include <unistd.h>

int main() {
    int n, i;
    pid_t pid;

    printf("Enter the value of 'n': ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        pid = fork();
        if (pid == 0) {
            printf("Child process created with PID: %d\n", getpid());
            break;
        }
    }

    if (pid > 0) {
        printf("Parent process with PID: %d\n", getpid());
    }

    return 0;
}
