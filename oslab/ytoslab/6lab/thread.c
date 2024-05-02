#include <stdio.h>
#include <pthread.h>

void *func(void *arg) {
    printf("In thread function\n");
    pthread_exit("Exit thread Function\n");
}

int main() {
    pthread_t thread;
    void *ret_value;

    printf("In main thread\n");
    pthread_create(&thread, NULL, func, NULL);
    pthread_join(thread, &ret_value);
    printf("%s \n", (char *)ret_value);

    return 0;
}

