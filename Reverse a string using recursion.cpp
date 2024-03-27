#include <stdio.h>
#include <string.h>

// Function to print the reverse of a string using recursion
void reverseString(char *str) {
    if (*str == '\0') {
        return;
    }

    reverseString(str + 1); // Recursively call for next character
    
    printf("%c", *str); // Print current character
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    printf("Reverse of the string: ");
    reverseString(str);
    printf("\n");
    
    return 0;
}

