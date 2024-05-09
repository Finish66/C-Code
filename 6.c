#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// -------------------- Practical --------------------
// P1 Use the pthread library to create a thread with NULL attributes.
void *func(void *args) {
  printf("Inside Thread function\n");
  pthread_exit(NULL);
}
int main() {
  pthread_t thread;
  pthread_create(&thread, NULL, func, NULL);
  pthread_join(thread, NULL);
}

// P2 Passing message from the main function to the thread.
void *func(void *msg) {
  // char *text = (char *)msg;
  int i = *(int *)msg;

  // printf("Message From Main: %s\n", text);
  printf("Message From Main: %d\n", i);
  pthread_exit(NULL);
}
int main() {
  pthread_t tid;
  char *msg = "Hello Thread";
  int params = 10;

  // pthread_create(&tid, NULL, func, (void *)msg);
  pthread_create(&tid, NULL, func, (void *)&params);
  pthread_join(tid, NULL);
  return 0;
}

// P3 Program where thread returns a value to the main function using pointers.
void *func(void *args) {
  int *returnValue = (int *)malloc(sizeof(int));
  *returnValue = 10;
  pthread_exit((void *)returnValue);
  // pthread_exit("Hello Main...."); // String
}
int main() {
  pthread_t thread;
  pthread_create(&thread, NULL, func, NULL);

  void *returnValue;
  pthread_join(thread, &returnValue);
  printf("Thread Returned: %d\n", *(int *)returnValue);

  // void *a;
  // pthread_join(thread, &a); // String
  // printf("Thread Returned: %s\n", (char *)a);
}

// -------------------- Questions --------------------
// Q1 Use pthread to concatenate multiple strings passed to the thread function.
void *func(void *args) {
  char **arr = (char **)args;
  char *str = (char *)malloc(1000 * sizeof(char));
  str[0] = '\0';
  for (int i = 0; arr[i] != NULL; i++) {
    strcat(str, arr[i]);
    strcat(str, " ");
  }
  printf("Concatenated String: %s\n", str);
  pthread_exit(NULL);
}
int main() {
  pthread_t thread;
  char *arr[] = {"Hello", "World", "From", "Thread", NULL};
  pthread_create(&thread, NULL, func, (void *)arr);
  pthread_join(thread, NULL);
}

// Q2 find the length of strings passed to the thread function.
void *func(void *args) {
  char **arr = (char **)args;
  for (int i = 0; arr[i] != NULL; i++) {
    printf("Length of %s: %ld\n", arr[i], strlen(arr[i]));
  }
  pthread_exit(NULL);
}
int main() {
  pthread_t thread;
  char *arr[] = {"Hello", "World", "From", "Thread", NULL};
  pthread_create(&thread, NULL, func, (void *)arr);
  pthread_join(thread, NULL);
}

// Q3 Use three threads to calculate the ave, Max, Min from array.
int n = 5;
int arr[] = {1, 2, 3, 4, 5};
int mx, mn, avg;
void *average(void *args) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  avg = sum / n;
  pthread_exit(NULL);
}
void *max(void *args) {
  mx = arr[0];
  for (int i = 0; i < n; i++) {
    if (arr[i] > mx)
      mx = arr[i];
  }
  pthread_exit(NULL);
}
void *min(void *args) {
  mn = arr[0];
  for (int i = 0; i < n; i++) {
    if (arr[i] < mn)
      mn = arr[i];
  }
  pthread_exit(NULL);
}
int main() {
  pthread_t t1, t2, t3;
  pthread_create(&t1, NULL, average, NULL);
  pthread_create(&t2, NULL, max, NULL);
  pthread_create(&t3, NULL, min, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  printf("Average: %d\nMax: %d\nMin: %d\n", avg, mx, mn);
}

// Q4 Implementing Merge Sort using threads.
#define ARRAY_SIZE 10
int array[ARRAY_SIZE] = {5, 3, 8, 2, 9, 1, 7, 4, 6, 0};
void merge(int *array, int start, int mid, int end) {
  int n1 = mid - start + 1;
  int n2 = end - mid;
  int left[n1], right[n2];
  for (int i = 0; i < n1; i++) {
    left[i] = array[start + i];
  }
  for (int j = 0; j < n2; j++) {
    right[j] = array[mid + 1 + j];
  }
  int i = 0, j = 0, k = start;
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      array[k++] = left[i++];
    } else {
      array[k++] = right[j++];
    }
  }
  while (i < n1) {
    array[k++] = left[i++];
  }
  while (j < n2) {
    array[k++] = right[j++];
  }
}
void *merge_sort(void *args) {
  int *bounds = (int *)args;
  int start = bounds[0];
  int end = bounds[1];
  if (start < end) {
    int mid = start + (end - start) / 2;
    merge_sort((void *)&(int[]){start, mid});
    merge_sort((void *)&(int[]){mid + 1, end});
    merge(array, start, mid, end);
  }
  pthread_exit(NULL);
}
int main() {
  pthread_t merge_sort_thread;
  pthread_create(&merge_sort_thread, NULL, merge_sort,
                 (void *)&(int[]){0, ARRAY_SIZE - 1});
  pthread_join(merge_sort_thread, NULL);
  printf("Sorted array: ");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}

// Q5 generate multiple threads ans display its unique ID
void *func(void *i) {
  int id = *(int *)i;
  printf("Thread ID: %d\n", id);
  pthread_exit(NULL);
}
int main() {
  int n = 3;
  pthread_t threads[n];
  int ids[n];
  for (int i = 0; i < n; i++) {
    ids[i] = i;
    pthread_create(&threads[i], NULL, func, &ids[i]);
  }
  for (int i = 0; i < n; i++) {
    pthread_join(threads[i], NULL);
  }
}

// Q6 Use pthread_exit for resource cleanup, pthread_cancel for abrupt
// termination

void *func(void *args) {
  int id = *(int *)args;
  if (id == 0) {
    printf("Thread %d: Starting graceful termination...\n", id);
    sleep(2);
    printf("Thread %d: Cleaning up resources...\n", id);
    printf("Thread %d: Exiting gracefully...\n", id);
    pthread_exit(NULL);
  } else {
    printf("Thread %d: Starting abrupt termination...\n", id);
    pthread_cancel(pthread_self());
  }
}
int main() {
  int n = 3;
  pthread_t threads[n];
  int ids[n];
  for (int i = 0; i < n; i++) {
    ids[i] = i;
    pthread_create(&threads[i], NULL, func, &ids[i]);
  }
  for (int i = 0; i < n; i++) {
    pthread_join(threads[i], NULL);
  }
}
