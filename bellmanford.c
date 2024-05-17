#include <stdio.h>

void bellmanford(int wmat[10][10], int n, int s)
{
    int distance[10], cost[10][10];
    
    // Initialize cost matrix from input matrix wmat
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (wmat[i][j] == 0 && i != j)  // Assuming 0 means no edge, except for self-loops
            {
                cost[i][j] = 9999;  // Use a large number to represent infinity
            }
            else
            {
                cost[i][j] = wmat[i][j];
            }
        }
    }
    
    // Initialize distance array
    for (int i = 0; i < n; i++)
    {
        distance[i] = 9999;  // Use a large number to represent infinity
    }
    distance[s] = 0;
    
    // Applying Bellman-Ford algorithm
    for (int k = 0; k < n - 1; k++)  // Repeat n-1 times
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (distance[j] > distance[i] + cost[i][j])
                {
                    distance[j] = distance[i] + cost[i][j];
                }
            }
        }
    }
    
    // Check for negative weight cycles (not necessary in this example)

    // Print shortest distances from source (s)
    for (int i = 0; i < n; i++)
    {
        printf("Shortest distance to node %d: %d\n", i, distance[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of vertices (max 10): ");
    scanf("%d", &n);
    
    int graph[10][10];
    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    
    // Call Bellman-Ford function with user input graph
    bellmanford(graph, n, 0);
    
    return 0;
}
