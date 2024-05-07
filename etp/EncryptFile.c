//Write a C program that encrypts a text file using a simple encryption technique and saves the encrypted content to a new file.


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int sourceFd, destFd;
    char buffer[BUFFER_SIZE];
    char sourceFile[256], destFile[256];

    printf("Enter the source file name: ");
    scanf("%s", sourceFile);

    sourceFd = open(sourceFile, O_RDONLY);
    if (sourceFd == -1) {
        perror("open");
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
        for (int i = 0; i < bytesRead; i++) {
            buffer[i] += 3; // Simple encryption: add 3 to each character
        }
        write(destFd, buffer, bytesRead);
    }

    close(sourceFd);
    close(destFd);
    return 0;
}
