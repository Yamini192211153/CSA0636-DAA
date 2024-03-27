#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num, int i) {
    if (num <= 2) {
        if (num == 2)
            return true;
        else
            return false;
    }
    if (num % i == 0)
        return false;
    if (i * i > num)
        return true;
    return isPrime(num, i + 1);
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num <= 1) {
        printf("The number is not prime.\n");
    } else {
        if (isPrime(num, 2))
            printf("%d is a prime number.\n", num);
        else
            printf("%d is not a prime number.\n", num);
    }

    return 0;
}

