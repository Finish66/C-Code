#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>


int main() {
    pid_t pid;
    int fd;
    char content[100];

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    } else if (pid == 0) {
        printf("child process\n");

        fd = open("relation.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        close(fd);
        printf("file created by child\n");
    } else {
        printf("parent process\n");
        wait(NULL);
        fd = open("relation.txt", O_WRONLY | O_APPEND);

        printf("Enter content: ");
        scanf("%[^\n]s", content);
        
        write(fd, content, strlen(content));
        close(fd);
        printf("written to file by parent\n");
    }

    return 0;
}
