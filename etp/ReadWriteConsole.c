//2. Program to Read from Console and Write to Console

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    // 0 is the file descriptor of standard input.
    ssize_t bytesRead = read(0, buffer, BUFFER_SIZE);
    if (bytesRead == -1) {
        perror("read");
        return 1;
    }
    write(1, buffer, bytesRead); // 1 is the file descriptor of standard output.
    return 0;
}


