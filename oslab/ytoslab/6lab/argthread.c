#include <stdio.h>
#include <pthread.h>


void *func(void *arg){
	int *p = (int *) arg;
	printf("Hello by thread 1\n");
	printf("Argument %d\n",*p);
	return NULL;
}


int main(){
	
	void *status;
	pthread_t thread1;
	int funarg = 10;
	pthread_create(&thread1, NULL, func, (void *)&funarg);
	pthread_join(thread1, &status);
	printf("-> %s\n",(char *) status);
	return 0;
}


