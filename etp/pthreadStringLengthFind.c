//Exercise 2: Create a pthread program to find the length of strings passed to the thread function.

#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *find_string_length(void *arg) {
    char *string = (char *)arg;
    int len = strlen(string);
    return (void *)&len;
}

int main() {
    char *string = "Hello, World!";
    pthread_t thread_id;
    void *result;
    pthread_create(&thread_id, NULL, find_string_length, string);
    pthread_join(thread_id, &result);
    printf("Length of the string: %d\n", *((int *)result));
    return 0;
}
