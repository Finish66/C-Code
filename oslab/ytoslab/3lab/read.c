#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd;
	char buf[10];
	fd = open("sample.txt",O_RDONLY);

	if(fd < 0){
		perror("open");
		return 1;
	}
	
	if(read(fd, buf, 10) != 10){
		perror("read");
		return 1;
	}
	
	buf[10] = '\0';
       	printf("%s", buf);	
		
	
}
