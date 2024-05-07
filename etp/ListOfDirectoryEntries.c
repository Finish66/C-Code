//Exercise 2: Write a program that opens the current directory using opendir and reads its contents using readdir, then displays the list of directory entries.

#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }
    printf("Contents of the current directory:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}
