#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// -------------------- Practical --------------------
// P1 Race Condition
int shared = 0;
void *func(void *id) {
  int i = *(int *)id;
  printf("Thread %d running...\n", i);
  for (int i = 0; i < 1000000; i++) {
    shared++;
  }
  pthread_exit(NULL);
}
int main() {
  int n = 3;
  pthread_t threads[n];
  for (int i = 0; i < n; i++) {
    pthread_create(&threads[i], NULL, func, (void *)&i);
  }
  for (int i = 0; i < n; i++) {
    pthread_join(threads[i], NULL);
  }
  printf("The shared value is: %d\n", shared);
  return 0;
}

// P2 Avoid Race Condition using Semaphore
int shared = 1;
sem_t s;

void *func1() {
  int x;
  sem_wait(&s);
  x = shared;
  printf("Thread1 reads value as x: %d\n", x);
  x++;
  printf("After local Updation by thread1 x: %d\n", x);
  sleep(1);
  shared = x;
  printf("Value of shared variable updated by the thread1 is: %d\n", shared);
  sem_post(&s);
}
void *func2() {
  int y;
  sem_wait(&s);
  y = shared;
  printf("Thread2 reads value as y: %d\n", y);
  y--;
  printf("After local Updation by thread2 y: %d\n", y);
  sleep(1);
  shared = y;
  printf("Value of shared variable updated by the thread2 is: %d\n", shared);
  sem_post(&s);
}
int main() {
  sem_init(&s, 0, 1);
  pthread_t th1, th2;
  pthread_create(&th1, NULL, func1, NULL);
  pthread_create(&th2, NULL, func2, NULL);
  pthread_join(th1, NULL);
  pthread_join(th2, NULL);
  printf("Final Value of the shared var: %d\n", shared);
}

// P2 Avoid Race Condition using Mutex
int shared = 0;
pthread_mutex_t mutex;
void *func(void *i) {
  int id = *(int *)i;
  printf("Thread %d running...\n", id);
  for (int i = 0; i < 100000000; i++) {
    pthread_mutex_lock(&mutex);
    shared++;
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}
int main() {
  int n = 3;
  pthread_t thread[n];
  pthread_mutex_init(&mutex, NULL);
  for (int i = 0; i < n; i++) {
    pthread_create(&thread[i], NULL, func, (void *)&i);
  }
  for (int i = 0; i < n; i++) {
    pthread_join(thread[i], NULL);
  }
  pthread_mutex_destroy(&mutex);
  printf("Shared value is: %d\n", shared);
}

// P3 Avoid Race Condition using Semaphore
int shared = 0;
sem_t semaphore;
void *func(void *arg) {
  int id = *((int *)arg);
  printf("Thread %d running...\n", id);
  for (int i = 0; i < 10000000; i++) {
    sem_wait(&semaphore);
    shared++;
    sem_post(&semaphore);
  }
  pthread_exit(NULL);
}
int main() {
  int n = 3;
  pthread_t threads[n];
  int thread_ids[n];
  sem_init(&semaphore, 0, 1);
  for (int i = 0; i < n; i++) {
    thread_ids[i] = i;
    pthread_create(&threads[i], NULL, func, (void *)&thread_ids[i]);
  }
  for (int i = 0; i < n; i++) {
    pthread_join(threads[i], NULL);
  }
  printf("Shared value is: %d\n", shared);
  sem_destroy(&semaphore);
  return 0;
}

// -------------------- Questions --------------------
// Q1 Producer Consumer Problem using mutex
int BUFFER_SIZE = 5;
int buffer[5];
int count = 0;
int last_consumed_index = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_producer = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_consumer = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
  int item;
  int iterations = 0;
  while (iterations < 10) { // exit after 10 iterations
    item = rand() % 100;    // generate a random item
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
void *consumer(void *arg) {
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

// Q2 Producer Consumer using semaphore
#define BUFFER_SIZE 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t mutex, empty, full;

void produce(int item) {
  buffer[in] = item;
  in = (in + 1) % BUFFER_SIZE;
}
int consume() {
  int item = buffer[out];
  out = (out + 1) % BUFFER_SIZE;
  return item;
}
void *producer(void *arg) {
  int producerID = *(int *)arg;
  for (int i = 0; i < 5; ++i) {
    sem_wait(&empty);
    sem_wait(&mutex);
    int item = rand() % 100;
    printf("Producer %d produced item %d\n", producerID, item);
    produce(item);
    sem_post(&mutex);
    sem_post(&full);
    usleep(rand() % 1000000);
  }
  return NULL;
}
void *consumer(void *arg) {
  int consumerID = *(int *)arg;
  for (int i = 0; i < 5; ++i) {
    sem_wait(&full);
    sem_wait(&mutex);
    int item = consume();
    printf("Consumer %d consumed item %d\n", consumerID, item);
    sem_post(&mutex);
    sem_post(&empty);
    usleep(rand() % 1000000);
  }
  return NULL;
}
int main() {
  pthread_t producerThreads[NUM_PRODUCERS];
  pthread_t consumerThreads[NUM_CONSUMERS];

  sem_init(&mutex, 0, 1);
  sem_init(&empty, 0, BUFFER_SIZE);
  sem_init(&full, 0, 0);

  for (int i = 0; i < NUM_PRODUCERS; ++i) {
    int *producerID = malloc(sizeof(int));
    *producerID = i;
    pthread_create(&producerThreads[i], NULL, producer, producerID);
  }
  for (int i = 0; i < NUM_CONSUMERS; ++i) {
    int *consumerID = malloc(sizeof(int));
    *consumerID = i;
    pthread_create(&consumerThreads[i], NULL, consumer, consumerID);
  }
  for (int i = 0; i < NUM_PRODUCERS; ++i) {
    pthread_join(producerThreads[i], NULL);
  }
  for (int i = 0; i < NUM_CONSUMERS; ++i) {
    pthread_join(consumerThreads[i], NULL);
  }

  sem_destroy(&mutex);
  sem_destroy(&empty);
  sem_destroy(&full);
  return 0;
}

// Q3 Reader writer problem using semaphore
int NUM_READERS = 3;
int NUM_WRITERS = 2;
int MAX_ATTEMPTS = 5;
int shared_data = 0;
int num_readers = 0;
sem_t mutex;
sem_t wrt;

void *reader(void *arg) {
  int id = *(int *)arg;
  int attempts = 0;
  while (attempts < MAX_ATTEMPTS) {
    sem_wait(&mutex);
    num_readers++;
    if (num_readers == 1) {
      sem_wait(&wrt);
    }
    sem_post(&mutex);
    printf("Reader %d read shared_data as %d\n", id, shared_data);
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
void *writer(void *arg) {
  int id = *(int *)arg;
  int attempts = 0;
  while (attempts < MAX_ATTEMPTS) {
    sem_wait(&wrt);
    shared_data++;
    printf("Writer %d wrote shared_data as %d\n", id, shared_data);
    sem_post(&wrt);
    attempts++;
  }
  pthread_exit(NULL);
}
int main() {
  sem_init(&mutex, 0, 1);
  sem_init(&wrt, 0, 1);

  pthread_t reader_threads[NUM_READERS];
  int reader_ids[NUM_READERS];
  for (int i = 0; i < NUM_READERS; i++) {
    reader_ids[i] = i;
    pthread_create(&reader_threads[i], NULL, reader, &reader_ids[i]);
  }
  pthread_t writer_threads[NUM_WRITERS];
  int writer_ids[NUM_WRITERS];
  for (int i = 0; i < NUM_WRITERS; i++) {
    writer_ids[i] = i;
    pthread_create(&writer_threads[i], NULL, writer, &writer_ids[i]);
  }
  for (int i = 0; i < NUM_READERS; i++) {
    pthread_join(reader_threads[i], NULL);
  }
  for (int i = 0; i < NUM_WRITERS; i++) {
    pthread_join(writer_threads[i], NULL);
  }
  sem_destroy(&mutex);
  sem_destroy(&wrt);
  return 0;
}
