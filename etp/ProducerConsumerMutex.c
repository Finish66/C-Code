//Producer & Consumer Using Mutex

#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 


int BUFFER_SIZE = 5; 
int buffer[5]; 
int count = 0; 
int last_consumed_index = 0; 

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t cond_producer = PTHREAD_COND_INITIALIZER; 
pthread_cond_t cond_consumer = PTHREAD_COND_INITIALIZER; 

void* producer(void* arg) {
    int item;
    int iterations = 0;
    while (iterations < 10) { // exit after 10 iterations
        item = rand() % 100; // generate a random item
        pthread_mutex_lock(&mutex);
        if (count == BUFFER_SIZE) {
            pthread_cond_wait(&cond_producer, &mutex);
        }
        if (count == 0) {
            last_consumed_index = 0; // reset last consumed index if buffer is empty
        }
        buffer[last_consumed_index++] = item;
        printf("Produced item: %d\n", item);
        count++;
        if (count == 1) {
            pthread_cond_signal(&cond_consumer);
        }
        pthread_mutex_unlock(&mutex);
        iterations++;
    }
    return NULL;
}

void* consumer(void* arg) {
    int item;
    int iterations = 0;
    while (iterations < 10) { // exit after 10 iterations
        pthread_mutex_lock(&mutex);
        if (count == 0) {
            pthread_cond_wait(&cond_consumer, &mutex);
        }
        item = buffer[--last_consumed_index];
        printf("Consumed item: %d\n", item);
        count--;
        if (count == BUFFER_SIZE - 1) {
            pthread_cond_signal(&cond_producer);
        }
        pthread_mutex_unlock(&mutex);
        iterations++;
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;
    srand(time(NULL)); // initialize the random seed

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}
