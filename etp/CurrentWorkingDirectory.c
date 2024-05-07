//Exercise 4: Write a program that uses the getcwd system call to retrieve the current working directory and displays it to the user.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return 1;
    }
    printf("Current working directory: %s\n", cwd);
    return 0;
}
