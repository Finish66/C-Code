//1. Program to Create and Open a File for Reading

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fileDescriptor;
    // Create a new file named "file.txt" and open it for reading
    fileDescriptor = open("file.txt", O_CREAT | O_RDONLY, 0644);
    if (fileDescriptor == -1) {
        perror("open");
        return 1;
    }
    close(fileDescriptor); // Close the file
    return 0;
}
