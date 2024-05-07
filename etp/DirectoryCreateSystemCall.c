//Q1 Create a C program that prompts the user to enter a directory name and uses system call to create the directory and inside that directory create 2 text files and 1 directory. Then open and read the directory and display the list of directory entries and delete the sub directory. (all should be done using system calls)


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main() {
    char dir_name[256];
    printf("Enter a directory name: ");
    scanf("%255s", dir_name);

    // Create the directory using system call
    char mkdir_cmd[256];
    sprintf(mkdir_cmd, "mkdir %s", dir_name);
    system(mkdir_cmd);

    // Create 2 text files and 1 directory inside the created directory
    char file1_cmd[256];
    sprintf(file1_cmd, "touch %s/file1.txt", dir_name);
    system(file1_cmd);

    char file2_cmd[256];
    sprintf(file2_cmd, "touch %s/file2.txt", dir_name);
    system(file2_cmd);

    char subdir_cmd[256];
    sprintf(subdir_cmd, "mkdir %s/subdir", dir_name);
    system(subdir_cmd);

    // Open and read the directory using opendir and readdir system calls
    DIR *dir;
    struct dirent *ent;
    dir = opendir(dir_name);
    if (dir == NULL) {
        printf("Unable to open directory\n");
        return 1;
    }

    printf("Directory entries:\n");
    while ((ent = readdir(dir))!= NULL) {
        printf("%s\n", ent->d_name);
    }

    closedir(dir);

    // Delete the sub directory using system call
    char rmdir_cmd[256];
    sprintf(rmdir_cmd, "rm -r %s/subdir", dir_name);
    system(rmdir_cmd);

    return 0;
}
