#include <stdio.h>

// Function to check if a number is perfect or not
int isPerfect(int num) {
    int sum = 0;

    // Find the sum of proper divisors of num
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Check if the sum of divisors is equal to num
    if (sum == num) {
        return 1; // num is a perfect number
    } else {
        return 0; // num is not a perfect number
    }
}

int main() {
    int num;

    // Input the number from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if the number is perfect or not
    if (isPerfect(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}

