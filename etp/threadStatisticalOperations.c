//Exercise 3: Implement a program that performs statistical operations (calculating average, max-imum, and minimum) for a set of numbers. Utilize three threads, where each thread performs its respective operation.

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    int *numbers;
    int num_numbers;
    int *result;
} stats_args;

void *calculate_average(void *arg) {
    stats_args *args = (stats_args *)arg;
    int sum = 0;
    for (int i = 0; i < args->num_numbers; i++) {
        sum += args->numbers[i];
    }
    *args->result = sum / args->num_numbers;
    return NULL;
}

void *calculate_maximum(void *arg) {
    stats_args *args = (stats_args *)arg;
    int max = args->numbers[0];
    for (int i = 1; i < args->num_numbers; i++) {
        if (args->numbers[i] > max) {
            max = args->numbers[i];
        }
    }
    *args->result = max;
    return NULL;
}

void *calculate_minimum(void *arg) {
    stats_args *args = (stats_args *)arg;
    int min = args->numbers[0];
    for (int i = 1; i < args->num_numbers; i++) {
        if (args->numbers[i] < min) {
            min = args->numbers[i];
        }
    }
    *args->result = min;
    return NULL;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int num_numbers = sizeof(numbers) / sizeof(numbers[0]);
    int results[3];
    stats_
