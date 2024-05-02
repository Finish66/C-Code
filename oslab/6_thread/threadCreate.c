#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *threadFunction(void *arg);
int i,j,n;

int main()
{
	pthread_t aThread;
	pthread_create(&aThread, NULL, threadFunction, NULL);

	// pthread_join(aThread, NULL);
	
	printf("Inside Main\n");
  
  for(int j = 20; j < 25 ;j++){
    printf("%d\n",j);
    sleep(1);
  }
}

void *threadFunction(void *arg){
  printf("Inside Thread\n");
  for(int i = 0 ; i < 5 ;i++){
    printf("%d\n",i);
    sleep(1);
  }
}
