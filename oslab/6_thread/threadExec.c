#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *threadFunction(void *arg);
int num[2] = {3, 4};

int main()
{
  pthread_t aThread;

  void *result;

  pthread_create(&aThread, NULL, threadFunction, (void *)num);
  pthread_join(aThread, &result);

  printf("Inside Main\n");
  printf("Thread returned: %s\n", (char *) result);
}

void *threadFunction(void *arg){
  printf("Inside Thread\n");
  int *x = arg;
  int sum = x[0] + x[1];
  printf("Sum is %d\n",sum);
  pthread_exit("Sum Calculated, Thread Exit");
}
