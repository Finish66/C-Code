#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10

int array[ARRAY_SIZE] = {5, 3, 8, 2, 9, 1, 7, 4, 6, 0};

// Function to perform merge sort on an array
void merge(int *array, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Create temporary arrays
    int left[n1], right[n2];

    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < n1; i++) {
        left[i] = array[start + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = array[mid + 1 + j];
    }

    // Merge the temporary arrays back into array[start..end]
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            array[k++] = left[i++];
        } else {
            array[k++] = right[j++];
        }
    }

    // Copy the remaining elements of left[], if any
    while (i < n1) {
        array[k++] = left[i++];
    }

    // Copy the remaining elements of right[], if any
    while (j < n2) {
        array[k++] = right[j++];
    }
}

// Thread function to perform merge sort on a portion of the array
void *merge_sort(void *args) {
    int *bounds = (int *)args;
    int start = bounds[0];
    int end = bounds[1];

    if (start < end) {
        int mid = start + (end - start) / 2;

        // Sort left half
        merge_sort((void *)&(int[]){start, mid});

        // Sort right half
        merge_sort((void *)&(int[]){mid + 1, end});

        // Merge sorted halves
        merge(array, start, mid, end);
    }

    pthread_exit(NULL);
}

int main() {
    // Create thread for merge sort
    pthread_t merge_sort_thread;
    pthread_create(&merge_sort_thread, NULL, merge_sort, (void *)&(int[]){0, ARRAY_SIZE - 1});

    // Wait for the merge sort thread to finish
    pthread_join(merge_sort_thread, NULL);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

