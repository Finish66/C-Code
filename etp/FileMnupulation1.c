//File Manipulation Using System Calls 
//Q1. Using system calls copy first half of the content of a already existing file to a newly created file and then again copy the rest remaining second half of the content of that older file to a another newly created file

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int a, b, c, n;
	char buff1[500];
	
	a = open("content.txt", O_RDONLY | O_CREAT, 0777);
	b = open("FirstHalf.txt", O_WRONLY | O_CREAT, 0777);
	c = open("SecondHalf.txt", O_WRONLY | O_CREAT, 0777);
	
	n = read(a, buff1, 500);
	
	read(a, buff1, n/2);
	write(b, buff1, n/2);
	
	lseek(a, n/2, SEEK_SET);
	read(a, buff1, n/2);
	write(c, buff1, n/2);
	
	return 0;
}
