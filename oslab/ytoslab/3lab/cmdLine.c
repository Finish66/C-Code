#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
	
	int fd;
	fd = open(argv[1], O_RDONLY);
	int fileSize = lseek(fd, 0, SEEK_END);

	printf("The size: %d", fileSize);
	return 0;
}
