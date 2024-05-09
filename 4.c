#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// P1 Prints the contents of a directory using system calls
int main() {
  DIR *dir;
  struct dirent *entry;
  dir = opendir(".");
  if (dir) {
    printf("Files in the current directory are:\n");
    while ((entry = readdir(dir)) != NULL) {
      printf("%s\n", entry->d_name);
    }
    closedir(dir);
  }
}

// P2 create a new directory named ”NewDirectory” within the file system
int main() {
  const char *dirName = "NewDirectory";
  mkdir(dirName, 0777);
  return 0;
}

// Q1 prompts the user to enter a directory name and uses the
// mkdir system call to create the directory.
int main() {
  char dirName[100];
  printf("Enter directory name: ");
  scanf("%s", dirName);
  mkdir(dirName, 0777);
}

// Q3 delete a directory specified by the user using the rmdir
int main() {
  char dirName[100];
  printf("Enter directory to delete: ");
  scanf("%s", dirName);
  if (rmdir(dirName) == 0) {
    printf("%s deleted.\n", dirName);
  } else {
    printf("Error deleting %s.\n", dirName);
  }
}

// Q4 Prints current working directory
int main() {
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("Current working directory: %s\n", cwd);
  } else {
    printf("Error Occurred\n");
    return 1;
  }
  return 0;
}
