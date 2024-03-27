#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num, int i) {
    if (i == 1) // Base case
        return true;
    if (num % i == 0)
        return false;
    return isPrime(num, i - 1); // Recursively check for divisibility
}

void generatePrimes(int n, int i) {
    if (i > n)
        return;
    if (isPrime(i, i / 2)) // Check if i is prime
        printf("%d ", i);
    generatePrimes(n, i + 1); // Recursively generate primes up to n
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    printf("Prime numbers up to %d are: ", n);
    generatePrimes(n, 2); // Start generating primes from 2
    printf("\n");

    return 0;
}

