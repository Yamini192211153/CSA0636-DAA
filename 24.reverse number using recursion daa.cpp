#include <stdio.h>

// Function to calculate the reverse of a given number recursively
int reverse(int num) {
    static int reversedNum = 0;

    // Base case
    if (num == 0)
        return 0;

    // Recursive call
    reversedNum = reversedNum * 10 + num % 10;
    reverse(num / 10);

    return reversedNum;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int reversed = reverse(num);

    printf("Reverse of %d is %d\n", num, reversed);

    return 0;
}

