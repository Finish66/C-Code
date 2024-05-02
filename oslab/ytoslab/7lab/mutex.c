#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;

int main() {

	if(pthread_mutex_init(&mutex, NULL) != 0){
		printf("Mutex faliled");
		return 1;	
	}
	if(pthread_mutex_lock(&mutex) != 0){
		printf("Lock Failed");
		return 1;
	}
	printf("In critical section\n");
	if(pthread_mutex_unlock(&mutex) != 0){
		printf("Unlock failed");
		return 1;
	}
	if(pthread_mutex_destroy(&mutex) != 0){
		printf("Destroy Failed");
		return 1;
	}
	return 0;
}

