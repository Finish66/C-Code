#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define SIZE 1024

int main(){
	char buf[SIZE];
	// Reading from Standard Input
	ssize_t writtenSize = read(0, buf, SIZE);
	// Writing on to the Standard output/ terminal
	write(1, buf, writtenSize);

	return 0;
}
