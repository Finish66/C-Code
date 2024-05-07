//Q6 Write a C program to create 2 threads where one thread is printing the multiplication table and other thread is printing addition table of a number which is taken from user and is passed as an argument to the thread printing the tables and after the threads have done their job, main program should print a success message.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *multiplication_table(void *arg) {
    int num = *((int *) arg);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
    return NULL;
}

void *addition_table(void *arg) {
    int num = *((int *) arg);
    for (int i = 1; i <= 10; i++) {
        printf("%d + %d = %d\n", num, i, num + i);
    }
    return NULL;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    pthread_t thread1, thread2;

    // Create threads
    pthread_create(&thread1, NULL, multiplication_table, (void *)&num);
    pthread_create(&thread2, NULL, addition_table, (void *)&num);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Multiplication and addition tables have been printed successfully.\n");

    return 0;
}
