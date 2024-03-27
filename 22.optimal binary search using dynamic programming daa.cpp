#include <stdio.h>
#include <limits.h>

int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int optimalBST(int keys[], int freq[], int n) {
    // Create a 2D array to store the results of subproblems
    int cost[n][n];

    // For a single key, the cost is equal to the frequency
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Consider chains of increasing length
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try making all keys in the interval keys[i..j] as root
            for (int r = i; r <= j; r++) {
                // Calculate the cost when keys[r] becomes the root of this subtree
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    // Return the result which is cost of optimal BST
    return cost[0][n - 1];
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];
    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &keys[i]);

    printf("Enter the corresponding frequencies:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &freq[i]);

    printf("Cost of optimal BST: %d\n", optimalBST(keys, freq, n));

    return 0;
}

