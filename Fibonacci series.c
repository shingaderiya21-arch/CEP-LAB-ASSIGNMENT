#include <stdio.h>

// Recursive factorial function
unsigned long long factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// Recursive Fibonacci function (returns nth Fibonacci number)
unsigned long long fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive sum of digits function
int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int num, n;

    // Factorial
    printf("Enter a number to find factorial: ");
    scanf("%d", &num);
    if (num < 0)
        printf("Factorial is not defined for negative numbers.\n");
    else
        printf("Factorial of %d is %llu\n", num, factorial(num));

    // Fibonacci
    printf("Enter the term (n) to find in Fibonacci series: ");
    scanf("%d", &n);
    if (n < 0)
        printf("Fibonacci is not defined for negative numbers.\n");
    else
        printf("Fibonacci term %d is %llu\n", n, fibonacci(n));

    // Sum of digits
    printf("Enter a number to find sum of digits: ");
    scanf("%d", &num);
    // Handle negative numbers by taking absolute value
    if (num < 0) num = -num;
    printf("Sum of digits of the number is %d\n", sumOfDigits(num));

    return 0;
}