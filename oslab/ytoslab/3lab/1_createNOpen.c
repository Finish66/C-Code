#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	// Open a file
	int fd = open("txt.txt", O_CREAT | O_RDONLY, 0644);
	
	printf("%d\n",fd);

	//Close a file
	close(fd);
	
	return 0;
}
