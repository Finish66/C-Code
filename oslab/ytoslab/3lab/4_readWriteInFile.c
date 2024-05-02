#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define SIZE 1024

int main(){

	char buf[SIZE];

	int readFD = open("4_source.txt", O_RDONLY);
	int writeFD = open("4_des.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	int bytesRead;

	while((bytesRead = read(readFD, buf, SIZE)) > 0){
		write(writeFD, buf, bytesRead);
	}
	
	close(readFD);
	close(writeFD);

	return 0;
}
