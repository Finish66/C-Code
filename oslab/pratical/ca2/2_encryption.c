


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int rfd, wfd;
    char ch;

    rfd = open("input.txt", O_RDONLY);
    printf("Opened File\n");
    wfd = open("encrypted.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    while (read(rfd, &ch, 1) > 0) {
        ch = ch + 33;
        write(wfd, &ch, 1);
    }   

    printf("Encryption Done\n");
    close(rfd);
    close(wfd);

    return 0;
}

