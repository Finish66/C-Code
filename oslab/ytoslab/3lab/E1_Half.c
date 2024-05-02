#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd,wfd, SIZE = 1024, c;
	off_t fileSize, offset;
	ssize_t byteRead, byteWritten;
	char buf[SIZE];

	fd = open("half.txt", O_RDONLY);
	fileSize = lseek(fd, 0, SEEK_END);

	printf("Enter choice (1,2): ");
	scanf("%d", &c);

	if(c == 1){
		offset = 0;
		fileSize /= 2;
	}	
	else if(c == 2){
		offset = fileSize / 2;
	}
	else{
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
