//Q2. Write a program using pthread to find the length of string, where strings are passed to thread function

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

char length1[100];
int length=0;

void *lengthstr(){
	length=strlen(length1);
	pthread_exit(NULL);
}


int main(){
	pthread_t thread;
	printf("* Enter the String: ");
	scanf("%[^\n]s", length1);
	
	pthread_create(&thread, NULL, lengthstr, NULL);
	pthread_join(thread, NULL);
	printf("* Total length of string is: %d \n", length);
	return 0;
}
