#include <stdio.h>
#include <stdlib.h>

struct Item { int weight; int value; };

int compare(const void *a, const void *b) {
    double ratio1 = (double)(((struct Item*)a)->value / (double)((struct Item*)a)->weight);
    double ratio2 = (double)(((struct Item*)b)->value / (double)((struct Item*)b)->weight);
    return (ratio1 < ratio2) ? 1 : ((ratio1 > ratio2) ? -1 : 0);
}

double fractionalKnapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);
    double totalValue = 0.0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int capacity, n;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d:\nWeight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Value: ");
        scanf("%d", &items[i].value);
    }
    printf("Maximum value in Knapsack = %.2lf\n", fractionalKnapsack(capacity, items, n));
    return 0;
}
