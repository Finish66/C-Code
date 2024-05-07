//4. Program to Read from and Write to Files

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    int readFd, writeFd;
    readFd = open("source.txt", O_RDONLY);
    if (readFd == -1) {
        perror("open");
        return 1;
    }
    writeFd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (writeFd == -1) {
        perror("open");
        close(readFd);
        return 1;
    }
    ssize_t bytesRead;
    while ((bytesRead = read(readFd, buffer, BUFFER_SIZE)) > 0) {
        write(writeFd, buffer, bytesRead);
    }
    close(readFd);
    close(writeFd);
    return 0;
}
