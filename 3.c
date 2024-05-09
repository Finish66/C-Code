#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// P1 Create and Open a File for Reading
int main() {
  int fd;
  fd = open("file.txt", O_CREAT | O_RDONLY, 0644);
  close(fd);
}

// P2 Read from Console and Write to Console
int main() {
  char buffer[100];
  ssize_t bytesRead = read(0, buffer, 100);
  write(1, buffer, bytesRead);
}

// P3 Append Data into a File
int main() {
  char data[] = "This need to be appended";
  int fd = open("file.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
  write(fd, data, strlen(data));
  close(fd);
}

// P4 Program to Read from and Write to Files
int main() {
  char buffer[1024];
  int read_fd = open("read.txt", O_RDONLY, 0644);
  int write_fd = open("write.txt", O_CREAT | O_WRONLY, 0644);
  ssize_t bytesRead;
  while ((bytesRead = read(read_fd, buffer, 1024)) > 0) {
    write(write_fd, buffer, bytesRead);
  }
  close(read_fd);
  close(write_fd);
}

// P5 reads characters from the 11th to the 20th position from a file
// named ”input.txt” using the lseek system call
int main() {
  int fd;
  char buffer[100];
  fd = open("input.txt", O_RDONLY);
  lseek(fd, 10, SEEK_SET);
  read(fd, buffer, 99);
  buffer[99] = '\0';
  printf("%s\n", buffer);
}

// Q1 Write a program in C using system calls that lets users choose to copy
// either the first
//  half or the second half of a file by entering 1 or 2.
int main() {
  int fd, wfd, SIZE = 1024, c;
  off_t fileSize, offset;
  ssize_t byteRead, byteWritten;
  char buf[SIZE];
  fd = open("half.txt", O_RDONLY);
  fileSize = lseek(fd, 0, SEEK_END);
  printf("Enter choice (1,2): ");
  scanf("%d", &c);
  if (c == 1) {
    offset = 0;
    fileSize /= 2;
  } else if (c == 2) {
    offset = fileSize / 2;
  } else {
    printf("Invalid Option.\n");
    return 1;
  }
  lseek(fd, offset, SEEK_SET);
  byteRead = read(fd, buf, fileSize);
  wfd = open("des.txt", O_WRONLY | O_TRUNC | O_CREAT);
  byteWritten = write(wfd, buf, byteRead);
  close(fd);
  close(wfd);
}

// Q2 Create a C program using system calls that keeps reading from the console
//  until the user types ’$’. Save the input data to a file called ’input.txt’.”
int main() {
  int SIZE = 1024;
  char buf[SIZE];
  while (read(0, buf, SIZE) > 0) {
    if (buf[0] == '$')
      break;
  }
  printf("You entered #\n");
}
