#include <stdio.h>
#include <limits.h>

#define V 10 // Maximum number of vertices (cities)

// Function to find the minimum of two numbers
int min(int x, int y) {
    return (x < y) ? x : y;
}

// Function to solve the TSP using dynamic programming
int tsp(int graph[][V], int mask, int pos, int dp[][V], int n) {
    // If all cities have been visited
    if (mask == (1 << n) - 1) {
        return graph[pos][0]; // Return the cost of returning to the starting city
    }

    // If the result is already cached
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    // Try to visit each unvisited city
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(graph, mask | (1 << city), city, dp, n);
            ans = min(ans, newAns);
        }
    }

    // Cache the result
    return dp[mask][pos] = ans;
}

int main() {
    int n;
    printf("Enter the number of cities (maximum %d): ", V);
    scanf("%d", &n);

    if (n > V || n < 1) {
        printf("Invalid number of cities. Please enter a number between 1 and %d.\n", V);
        return 1;
    }

    int graph[V][V];

    printf("Enter the distances between the cities:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // dp[mask][pos] stores the minimum cost of visiting all cities in the mask
    // starting from the current city 'pos'
    int dp[1 << V][V];

    // Initialize dp array with -1
    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = -1;
        }
    }

    // Start from the first city
    int startCity = 0;

    // Compute the minimum cost using dynamic programming
    int minCost = tsp(graph, 1, startCity, dp, n); // '1' represents that the start city has been visited

    printf("Minimum cost for TSP: %d\n", minCost);

    return 0;
}


