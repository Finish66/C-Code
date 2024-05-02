#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

// Function to be executed by each thread
void *thread_function(void *arg) {
    int thread_id = *((int *)arg); // Unique thread ID
    printf("Thread %d: Hello, I am thread %d!\n", thread_id, thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS]; // Array to hold thread IDs
    int thread_ids[NUM_THREADS]; // Array to hold thread IDs

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i; // Assigning unique ID to each thread
        pthread_create(&threads[i], NULL, thread_function, (void *)&thread_ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

