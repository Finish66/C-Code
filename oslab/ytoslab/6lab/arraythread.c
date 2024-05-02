#include <stdio.h>
#include <pthread.h>

void *func(void *arg){
	int *p = (int *)arg;
	printf("At index 0: %d\n",p[0]);
	pthread_exit(NULL);
}

int main(){
	pthread_t thread;
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	pthread_create(&thread, NULL, func, (void *)arr);
	pthread_join(thread, NULL);
	return 0;
}
