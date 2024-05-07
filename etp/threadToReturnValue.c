//A C program where a thread returns a value to the main function using pointers:

#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 1

void* thread_function(void* arg) {
    int* return_value = malloc(sizeof(int));
    *return_value = 143; // Set the return value
    pthread_exit(return_value);
}

int main() {
    pthread_t thread_ids[NUM_THREADS];
    int* thread_return;

    pthread_create(&thread_ids[0], NULL, thread_function, NULL);
    pthread_join(thread_ids[0], (void**)&thread_return);
    printf("Value returned from thread: %d\n", *thread_return);
    free(thread_return); // Free allocated memory for return value
    return 0;
}
