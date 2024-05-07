//Q10 Write a c program and use system calls : 1.Create a folder and inside it create 3 more folders. and my section 2.Create two file inside the parent folder and write to it. ("Hello my name is ) and on the second file write ("My section and roll no. Is ") is Now create a child process where child merges the two file into a third file and parent overwrites the first file with the statement ("This file has been overwritten by your name") Keep directory names as - d1, d2, d3, d4 And file names as - f1, f2, f3.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LEN 100

int main() {
    // Create parent directory
    if (mkdir("d1", 0777) == -1) {
        perror("mkdir");
        exit(1);
    }

    // Create child directories
    if (chdir("d1") == -1) {
        perror("chdir");
        exit(1);
    }

    if (mkdir("d2", 0777) == -1 || mkdir("d3", 0777) == -1 || mkdir("d4", 0777) == -1) {
        perror("mkdir");
        exit(1);
    }

    // Create and write to files
    if (open("f1", O_CREAT | O_WRONLY, 0777) == -1) {
        perror("open");
        exit(1);
    }

    if (write(1, "Hello my name is ", 16) == -1 || write(1, "attimo\n", 6) == -1) {
        perror("write");
        exit(1);
    }

    if (open("f2", O_CREAT | O_WRONLY, 0777) == -1) {
        perror("open");
        exit(1);
