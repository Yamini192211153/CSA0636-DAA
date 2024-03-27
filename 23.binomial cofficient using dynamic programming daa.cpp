#include<stdio.h>

// Function to calculate binomial coefficient using dynamic programming
unsigned long long binomialCoefficient(int n, int k) {
    unsigned long long C[n + 1][k + 1];
    int i, j;

    // Calculate value of binomial coefficient in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= i && j <= k; j++) {
            // Base cases
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

int main() {
    int n, k;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    // Validate input
    if (k < 0 || k > n) {
        printf("Invalid input: k should be between 0 and n\n");
        return 1; // Exit with error
    }

    // Calculate binomial coefficient
    unsigned long long result = binomialCoefficient(n, k);

    printf("Binomial coefficient C(%d, %d) = %llu\n", n, k, result);

    return 0;
}

