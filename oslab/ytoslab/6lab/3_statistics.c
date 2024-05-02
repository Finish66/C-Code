#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define n 5

int val[5] = {1,2,3,4,5};
int average, mn, mx;

void *ave(void *args){
	int sum = 0;
	for(int i = 0 ; i < n; i++){
		sum += val[i];
	}
	average = (float) sum / n;
	pthread_exit(NULL);
}

void *min(void *args){
	mn = val[0];

	for(int i = 0 ; i < n; i++){
		if(val[i] < mn)
			mn = val[i];
	}
	pthread_exit(NULL);
}

void *max (void *args){
	mx = val[0];
	for(int i = 0 ; i < n; i++){
		if(val[i] > mx)
			mx = val[i];
	}
	pthread_exit(NULL);
}


int main(){

	pthread_t t1,t2,t3;
	pthread_create(&t1, NULL, ave, NULL);
	pthread_create(&t2, NULL, min, NULL);
	pthread_create(&t3, NULL, max, NULL);
		
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);

	printf("Ave: %d\n", average);
	printf("Min: %d\n", mn);
	printf("Max: %d\n", mx);
}
