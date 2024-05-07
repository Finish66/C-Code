//A C program using the pthread library to create a thread with NULL attributes


#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Inside the new thread!\n");
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_function, NULL);
    pthread_join(thread_id, NULL);
    return 0;
}
