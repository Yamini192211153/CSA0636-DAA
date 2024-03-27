#include <stdio.h>
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

  
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

       
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int m, n;

    printf("Enter the number of elements in the first array (A): ");
    scanf("%d", &m);
    int A[m];

    printf("Enter the elements of the first array (A) in non-increasing order: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &A[i]);

    printf("Enter the number of elements in the second array (B): ");
    scanf("%d", &n);
    int B[n];

    printf("Enter the elements of the second array (B) in non-increasing order: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);

    int C[m + n]; 

    
    for (int i = 0; i < m; i++)
        C[i] = A[i];
    for (int j = 0; j < n; j++)
        C[m + j] = B[j];
    mergeSort(C, 0, m + n - 1);


    printf("Merged and sorted array: ");
    printArray(C, m + n);

    return 0;
}
