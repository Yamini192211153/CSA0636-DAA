#include <stdio.h>

void minMaxSequence(int arr[], int n) {
    int min_so_far = arr[0];
    int max_so_far = arr[0];
  
    for (int i = 0; i < n; i++) {
        if (arr[i] < min_so_far)
            min_so_far = arr[i];
        if (arr[i] > max_so_far)
            max_so_far = arr[i];
        printf("Minimum sequence value for %d: %d\n", arr[i], min_so_far);
        printf("Maximum sequence value for %d: %d\n", arr[i], max_so_far);
    }
}

int main() {
    int n;
  
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
  
    int arr[n];
  
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
  
    printf("\nMinimum and maximum value sequence for each number in the list:\n");
    minMaxSequence(arr, n);
  
    return 0;
}

