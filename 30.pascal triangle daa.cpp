#include <stdio.h>

void printPascalTriangle(int n) {
    int coefficients[n][n];

    for (int line = 0; line < n; line++) {
        for (int i = 0; i <= line; i++) {
           
            if (line == i || i == 0) {
                coefficients[line][i] = 1;
            } else {
               
                coefficients[line][i] = coefficients[line - 1][i - 1] + coefficients[line - 1][i];
            }
           
            printf("%d ", coefficients[line][i]);
        }
       
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &n);

    printf("Pascal's triangle with %d rows:\n", n);
    printPascalTriangle(n);

    return 0;
}

