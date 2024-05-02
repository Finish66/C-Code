#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int SIZE = 1024;
	char buf [SIZE];
	while(read(0, buf, SIZE) > 0){
		if(buf[0] == '#')
			break;
	}
	printf("You entered #\n");
}
