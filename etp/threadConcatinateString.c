//Exercise 1: Develop a program using pthread to concatenate multiple strings passed to the thread function.

#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *concatenate_strings(void *arg) {
    char **strings = (char **)arg;
    int num_strings = *((int *)strings[-1]);
    int len = 0;
    for (int i = 0; i < num_strings; i++) {
        len += strlen(strings[i]);
    }
    char *result = (char *)malloc(len + 1);
    result[len] = '\0';
    for (int i = 0; i < num_strings; i++) {
        strcat(result, strings[i]);
    }
    return result;
}

int main() {
    char *strings[] = {"Hello", " ", "World", "!"};
    int num_strings = sizeof(strings) / sizeof(strings[0]) - 1;
    pthread_t thread_id;
    void *result;
    pthread_create(&thread_id, NULL, concatenate_strings, &strings);
    pthread_join(thread_id, &result);
    printf("Concatenated string: %s\n", (char *)result);
    free(result);
    return 0;
}
