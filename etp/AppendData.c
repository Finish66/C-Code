//3. Program to Append Data into a File

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char data[] = "This data will be appended to the file.\n";
    int fileDescriptor;
    fileDescriptor = open("file.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fileDescriptor == -1) {
        perror("open");
        return 1;
    }
    write(fileDescriptor, data, strlen(data));
    close(fileDescriptor);
    return 0;
}
