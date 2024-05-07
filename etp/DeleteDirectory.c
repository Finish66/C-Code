//xercise 3: Create a C program to delete a directory specified by the user using the rmdir system call.

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    char dirname[100];
    printf("Enter the directory name to delete: ");
    scanf("%s", dirname);
    if (rmdir(dirname) == -1) {
        perror("rmdir");
        return 1;
    }
    printf("Directory '%s' deleted successfully.\n", dirname);
    return 0;
}
