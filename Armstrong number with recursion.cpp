#include <stdio.h>
#include <math.h>

int countDigits(int num) {
    if (num == 0)
        return 0;
    else
        return 1 + countDigits(num / 10);
}

int isArmstrong(int num, int sum, int n) {
    if (num == 0)
        return sum;
    else
        return isArmstrong(num / 10, sum + pow(num % 10, n), n);
}

int main() {
    int num, sum = 0, digitCount, result;

    printf("Enter a number: ");
    scanf("%d", &num);

    digitCount = countDigits(num);

    result = isArmstrong(num, sum, digitCount);

    if (result == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}

