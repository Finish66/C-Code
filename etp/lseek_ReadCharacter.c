//5. Program to Read Characters from a File using lseek

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 11

int main() {
    int fileDescriptor;
    char buffer[BUFFER_SIZE];
    fileDescriptor = open("input.txt", O_RDONLY);
    if (fileDescriptor == -1) {
        perror("open");
        return 1;
    }
    if (lseek(fileDescriptor, 10, SEEK_SET) == -1) {
        perror("lseek");
        close(fileDescriptor);
        return 1;
    }
    read(fileDescriptor, buffer, BUFFER_SIZE - 1);
    buffer[BUFFER_SIZE - 1] = '\0';
    printf("Characters from 11th to 20th position: %s\n", buffer);
    close(fileDescriptor);
    return 0;
}
