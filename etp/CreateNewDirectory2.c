//Exercise 1: Create a C program that prompts the user to enter a directory name and uses the mkdir system call to create the directory.

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    char dirname[100];
    printf("Enter the directory name: ");
    scanf("%s", dirname);
    if (mkdir(dirname, 0755) == -1) {
        perror("mkdir");
        return 1;
    }
    printf("Directory '%s' created successfully.\n", dirname);
    return 0;
}
