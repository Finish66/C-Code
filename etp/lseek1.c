//Here is the C program that uses the lseek() system call to read 10 characters from the file "seeking" and print them on the screen, then read another 10 characters and print them on the screen:

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int n, f;
    char buff[10];

    f = open("seeking", O_RDWR);
    if (f == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read the first 10 characters and print them
    n = read(f, buff, 10);
    if (n == -1) {
        perror("Error reading from file");
        return 1;
    }
    write(1, buff, 10);

    // Move the file pointer to the beginning of the file using lseek()
    lseek(f, 0, SEEK_SET);

    // Read another 10 characters and print them
    n = read(f, buff, 10);
    if (n == -1) {
        perror("Error reading from file");
        return 1;
    }
    write(1, buff, 10);

    close(f);
    return 0;
}
