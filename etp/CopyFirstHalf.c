//Write a program in C using system calls that lets users choose to copy either the first half or the second half of a file by entering 1 or 2.


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int sourceFd, destFd;
    char buffer[BUFFER_SIZE];
    char sourceFile[256], destFile[256];
    int choice;

    printf("Enter the source file name: ");
    scanf("%s", sourceFile);

    sourceFd = open(sourceFile, O_RDONLY);
    if (sourceFd == -1) {
        perror("open");
        return 1;
    }

    printf("Enter 1 to copy the first half or 2 to copy the second half: ");
    scanf("%d", &choice);

    off_t fileSize = lseek(sourceFd, 0, SEEK_END);
    off_t halfSize = fileSize / 2;

    if (choice == 1) {
        lseek(sourceFd, 0, SEEK_SET);
    } else if (choice == 2) {
        lseek(sourceFd, halfSize, SEEK_SET);
    } else {
        printf("Invalid choice\n");
        close(sourceFd);
        return 1;
    }

    printf("Enter the destination file name: ");
    scanf("%s", destFile);

    destFd = open(destFile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destFd == -1) {
        perror("open");
        close(sourceFd);
        return 1;
    }

    ssize_t bytesRead;
    while ((bytesRead = read(sourceFd, buffer, BUFFER_SIZE)) > 0) {
        write(destFd, buffer, bytesRead);
    }

    close(sourceFd);
    close(destFd);
    return 0;
}
