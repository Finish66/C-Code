#include <stdio.h>
#include <pthread.h>
#include <string.h>



void *func(void* args){
	char ** str = (char **)args;
	
	for(int i = 0; str[i] != NULL; i++){
		
		int len = 0;
		while(str[i][len] != '\0'){
			len++;
		}
		printf("Len of %s : %d\n", str[i], len);
	}
	pthread_exit(NULL);
}

int main(){
	
	char* str[] = {"Hello", "Sai", NULL};
	pthread_t thread;
	pthread_create(&thread, NULL, func, (void *) str);
	pthread_join(thread, NULL);

	return 0;
}
