// A C program that creates a thread and passes a message from the main function to the thread:

#include <stdio.h>
#include <pthread.h>

void* thread_function(void* message) {
    printf("Message received in thread: %s\n", (char*) message);
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_function, "Hello from the main thread!");
    pthread_join(thread_id, NULL);
    return 0;
}
