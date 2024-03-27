#include <stdio.h>
int min(int a, int b) {
    return (a < b) ? a : b;
}
int gcd(int a, int b, int i) {
    if (i == 1)
        return 1;
    else if (a % i == 0 && b % i == 0)
        return i;
    else
        return gcd(a, b, i - 1);
}

int main() {
    int num1, num2, result;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    result = gcd(num1, num2, min(num1, num2));

    printf("GCD of %d and %d is %d\n", num1, num2, result);

    return 0;
}

