//Q7 Write a script in Linux with C that defines a function to calculate the factorial of a user given number ?


#include <stdio.h>

long long int factorial(int num) {
    if (num == 0) {
        return 1;
    }
    return num * factorial(num - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    long long int result = factorial(num);
    printf("Factorial of %d is %lld\n", num, result);

    return 0;
}
