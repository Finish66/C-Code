#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>


void *func(void *args){
	
	char **arr = (char **)args;
	char* str = (char *) malloc(1000);
	str[0] = '\0';
	
	for(int i = 0 ; arr[i] != NULL; i++){
		strcat(str, arr[i]);
	}

	printf("%s\n",str);
	return(NULL);
}


int main(){
	
	char *arr[] = {"Hello", "Sai", NULL};
	pthread_t thread;
	pthread_create(&thread, NULL, func, (void *) arr);
	pthread_join(thread, NULL);
	
	return 0;
}
