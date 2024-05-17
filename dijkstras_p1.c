#include <stdio.h>

void dijkstras(int wmat[10][10], int n, int s)
{
    int distance[10], visited[10], cost[10][10], mindistance, nextnode;
    
    // Initialize cost matrix from input matrix wmat
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (wmat[i][j] == 0)
            {
                cost[i][j] = 9999;
            }
            else
            {
                cost[i][j] = wmat[i][j];
            }
        }
    }
    
    // Initialize distance and visited arrays
    for (int i = 0; i < n; i++)
    {
        distance[i] = cost[s][i];
        visited[i] = 0;
    }
    distance[s] = 0;
    visited[s] = 1;
    
    // Apply Dijkstra's algorithm
    int count = 1;
    while (count < n)
    {
        mindistance = 9999;
        for (int i = 0; i < n; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (distance[i] > mindistance + cost[nextnode][i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                }
            }
        }
        count++;
    }
    
    // Print shortest distances from source (s)
    for (int i = 0; i < n; i++)
    {
        printf("Shortest distance from node %d to node %d is %d\n", s, i, distance[i]);
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
    
    // Call Dijkstra's function with user input graph
    dijkstras(graph, n, 0);
    
    return 0;
}
