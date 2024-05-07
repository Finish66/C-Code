// Open() system call to read the first 10 character

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int n, fd;
    char buffer[50];

    fd = open("test.txt", O_RDONLY); // opens test.txt in read mode and saves the file descriptor in integer fd
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    printf("The file descriptor of the file is: %d\n", fd); // prints the file descriptor value

    n = read(fd, buffer, 10); // reads 10 characters from the file pointed to by file descriptor fd and saves them in buffer
    if (n == -1) {
        perror("Error reading from file");
        return 1;
    }

    write(1, buffer, n); // writes to the screen from the buffer
    close(fd); // closes the file descriptor

    return 0;
}
