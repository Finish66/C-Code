#include <stdio.h>
#include <pthread.h>


void *factorial(void *arg){
	int *a = (int *) arg;
	int fact = 1;
	for(int i = 1; i <= *a; i++){
		fact *= i;
	}
	printf("Factorial: %d\n",fact);
	return NULL;
}

void *evenodd(void *arg){
	int *a = (int *) arg;
	if(*a & 1)
		printf("Its Odd\n");
	else
		printf("Its Even\n");
	return NULL;
}


int main(){
	int n;
	scanf("%d", &n);
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, factorial, (void *) &n);
	pthread_create(&thread2, NULL, evenodd, (void *) &n);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}
