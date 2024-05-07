//File Manupulation

//Q2. Using system calls write a program which reads from console until user types '$' and the content which is written on the console before '$' copy that content to a newly created file

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int a, b=0;
	char buff1[500];
	scanf("%[^\n]s", buff1);
	
	a = open("Output$.txt", O_WRONLY | O_CREAT, 0777);
	
	for(int i=0; i<500; i++){
		if(buff1[i] == '$'){
			printf("You can not write after '$' Symbol \n");
			break;
		}
		
		else{
			b++;
		}
	}
	
	char buff2[b];
	
	for(int i=0; i<b; i++){
		buff2[i]=buff1[i];
	}
	
	write(a, buff2, b);
	return 0;
}
