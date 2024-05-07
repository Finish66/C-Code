//Reader Writer Problem using Semaphore:

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int NUM_READERS = 3;
int NUM_WRITERS = 2;
int MAX_ATTEMPTS = 5;

// Shared data
int shared_data = 0;
int num_readers = 0;

// Semaphores
sem_t mutex;
sem_t wrt;

// Reader function
void *reader(void *arg) {
    int id = *(int*)arg;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        // Entry section
        sem_wait(&mutex);
        num_readers++;
        if (num_readers == 1) {
            sem_wait(&wrt);
        }
        sem_post(&mutex);

        // Critical section
        printf("Reader %d read shared_data as %d\n", id, shared_data);

        // Exit section
        sem_wait(&mutex);
        num_readers--;
        if (num_readers == 0) {
            sem_post(&wrt);
        }
        sem_post(&mutex);

        attempts++;
    }

    pthread_exit(NULL);
}

// Writer function
void *writer(void *arg) {
    int id = *(int*)arg;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        // Entry section
        sem_wait(&wrt);

        // Critical section
        shared_data++;
        printf("Writer %d wrote shared_data as %d\n", id, shared_data);

        // Exit section
        sem_post(&wrt);

        attempts++;
    }

    pthread_exit(NULL);
}

int main() {
    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create reader threads
    pthread_t reader_threads[NUM_READERS];
    int reader_ids[NUM_READERS];
    for (int i = 0; i < NUM_READERS; i++) {
        reader_ids[i] = i;
        pthread_create(&reader_threads[i], NULL, reader, &reader_ids[i]);
    }

    // Create writer threads
    pthread_t writer_threads[NUM_WRITERS];
    int writer_ids[NUM_WRITERS];
    for (int i = 0; i < NUM_WRITERS; i++) {
        writer_ids[i] = i;
        pthread_create(&writer_threads[i], NULL, writer, &writer_ids[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(reader_threads[i], NULL);
    }
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writer_threads[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
