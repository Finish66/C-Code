#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


void *calsum(void *arg) {
    int *nums = (int *)arg;
    int num1 = nums[0]; 
    int num2 =nums[1]; 
    int *result =(int *) malloc(sizeof(int)); 

    *result = num1 + num2; 
    pthread_exit(result);
}

int main() {
    pthread_t t1;
    int nums[2]; 
    int *sum; 

    printf("enter num1: ");
    scanf("%d", &nums[0]);
    printf("enter num2: ");
    scanf("%d", &nums[1]);

    pthread_create(&t1, NULL, calsum, (void *)nums);
    pthread_join(t1,(void *) &sum);

    printf("sum of %d and %d is: %d\n", nums[0], nums[1], *sum);

    return 0;
}
