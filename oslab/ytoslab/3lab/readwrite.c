#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(){

	char buf[10];
	read(0, buf, 10);
	write(1, buf, 10);

	return 0;

}
