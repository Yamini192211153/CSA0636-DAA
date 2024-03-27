#include <stdio.h>
void fibonacciSeries(int n, int fib[]) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int evenSumOfFibonacci(int n) {
    int fib[n + 1];
    int sum = 0;

    fibonacciSeries(n, fib);
    for (int i = 0; i <= n; i += 3) {
        sum += fib[i];
    }

    return sum;
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    int result = evenSumOfFibonacci(n);
    printf("Sum of even Fibonacci numbers up to %d terms: %d\n", n, result);

    return 0;
}
