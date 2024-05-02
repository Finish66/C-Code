#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define SIZE 11
int main(){

	int fd = open("input.txt", O_RDONLY | O_CREAT);
	int ft = lseek(fd, 10, SEEK_SET);
	
	char buf[SIZE];

	int bytesRead = read(fd, buf, SIZE - 1);
	buf[SIZE - 1] = '\0';
	printf("Characters from 11 - 20 : %s\n", buf);

	close(fd);
	return 0;	


}
