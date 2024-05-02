#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){
	
	char data[] = "This is the data to be written to a file\n";

	int fd = open("3_data.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	write(fd, data, strlen(data));
	close(fd);

	write(1, "Written The file\n", 15);

	close(fd);

}
