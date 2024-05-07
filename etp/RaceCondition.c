//Race Condition

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int NUM_THREADS = 2;
int shared = 0;

void *thread_func(void *arg) {
	int id = *(int *) arg;
	int local = 0;

	for (int i = 0; i < 1000000; i++) {
    	local = shared;
    	local++;
    	shared = local;
	}

	printf("Thread %d: shared = %d\n", id, shared);

	pthread_exit(NULL);
}

int main() {
	pthread_t threads[NUM_THREADS];
	int thread_ids[NUM_THREADS];

	for (int i = 0; i < NUM_THREADS; i++) {
    	thread_ids[i] = i;
    	pthread_create(&threads[i], NULL, thread_func, (void *) &thread_ids[i]);
	}

	for (int i = 0; i < NUM_THREADS; i++) {
    	pthread_join(threads[i], NULL);
	}

	printf("Final value of shared = %d\n", shared);

	return 0;
}

