#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 2

void *thread_function(void *arg) {
    int thread_id = *((int *)arg);
    
    // Graceful termination using pthread_exit
    if (thread_id == 0) {
        printf("Thread %d: Starting gracefull termination...\n", thread_id);
        sleep(2); // Simulating some work
        
        printf("Thread %d: Cleaning up resources...\n", thread_id);
        // Perform cleanup operations here
        
        printf("Thread %d: Exiting gracefully.\n", thread_id);
        pthread_exit(NULL);
    } 
    // Abrupt termination using pthread_cancel
    else {
        printf("Thread %d: Starting abrupt termination...\n", thread_id);
        pthread_cancel(pthread_self()); // Cancel the current thread
        
        // The following code will not be executed because the thread is cancelled
        printf("Thread %d: This line will not be printed.\n", thread_id);
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void *)&thread_ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

