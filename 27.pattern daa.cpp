#include <stdio.h>

// Recursive function to print the pattern
void printPattern(int n, int row, int col) {
    // Base case: if the current row exceeds n, return
    if (row > n)
        return;

    // Print numbers from 1 to col
    if (col <= row) {
        printf("%d ", col);
        printPattern(n, row, col + 1);
    } else {
        // Move to the next row
        printf("\n");
        printPattern(n, row + 1, 1);
    }
}

int main() {
    int n;
    
    // Input value of n from the user
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    // Call the recursive function to print the pattern
    printPattern(n, 1, 1);
    
    return 0;
}
