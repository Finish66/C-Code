

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>

int main(){

    mkdir("dir_personal", 0777);
    int dir1 = sizeof("Directory is created\n");
    write(1,"Directory is created\n",dir1);


    int fd1 = open("dir_personal/file1.txt", O_WRONLY | O_CREAT, 0644);
    int fileSize1 = sizeof("This is the contents os file txt 1");
    write(fd1,"This is the contents os file txt 1",fileSize1);
    close(fd1);

    int fd2 = open("dir_personal/file2.txt", O_WRONLY | O_CREAT, 0644);
    int fileSize2 = sizeof("This is the contents os file txt 2");
    write(fd2,"This is the contents os file txt 2",fileSize2);
    close(fd2);

    DIR *dir;
    struct dirent *entry;

    dir = opendir("dir_personal");

    if(dir){
        printf("Contents of Directory: \n");
        while((entry = readdir(dir)) != NULL){
            printf("%s\n", entry->d_name);
        }
        closedir(dir);
    }
    return 0;
}
