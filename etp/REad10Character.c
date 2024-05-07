//Here is the C program that reads the first 10 characters from the file "test.txt" and writes them into a non-existing file "towrite.txt":

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int n, fd, fd1;
    char buffer[50];

    fd = open("test.txt", O_RDONLY);
    n = read(fd, buffer, 10);

    fd1 = open("towrite.txt", O_WRONLY | O_CREAT, 0642);
    // Use the pipe symbol (|) to separate O_WRONLY and O_CREAT

    write(fd1, buffer, n);

    return 0;
}
