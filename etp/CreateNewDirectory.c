//Write a C program to create a new directory named "NewDirectory" within the file system:

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    const char *dirname = "NewDirectory";

    // Creating a new directory named "NewDirectory"
    mkdir(dirname, 0777);

    return 0;
}
