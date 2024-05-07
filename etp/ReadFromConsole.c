//Create a C program using system calls that keeps reading from the console until the user types ’$’. Save the input data to a file called ’input.txt’.”



#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int fileDescriptor;
    char buffer[BUFFER_SIZE];
    char c;

    fileDescriptor = open("input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fileDescriptor == -1) {
        perror("open");
        return 1;
    }

    printf("Enter text (type '$' to finish): ");
    while (1) {
        ssize_t bytesRead = read(0, &c, 1);
        if (bytesRead == -1) {
            perror("read");
            close(fileDescriptor);
            return 1;
        }
        if (c == '$') {
            break;
        }
        write(fileDescriptor, &c, 1);
    }

    close(fileDescriptor);
    return 0;
}
