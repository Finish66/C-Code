#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

void *func1();
void *func2();
int shared = 1;
sem_t s;

int main(){
	
	sem_init(&s, 0, 1);
	pthread_t th1, th2;
	pthread_create(&th1, NULL, func1, NULL);
	pthread_create(&th2, NULL, func2, NULL);
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	printf("Final Value of the shared var: %d\n",shared);
}


void *func1(){
	int x;
	sem_wait(&s);
	x = shared;
	printf("Thread1 reads value as x: %d\n", x);
	x++;
	printf("After local Updation by thread1 x: %d\n",x);
	sleep(1);
	shared = x;
	printf("Value of shared variable updated by the thread1 is: %d\n", shared);
	sem_post(&s);
}

void *func2(){
	int y;
	sem_wait(&s);
	y = shared;
	printf("Thread2 reads value as y: %d\n", y);
	y--;
	printf("After local Updation by thread2 y: %d\n",y);
	sleep(1);
	shared = y;
	printf("Value of shared variable updated by the thread2 is: %d\n", shared);
	sem_post(&s);
}

























































