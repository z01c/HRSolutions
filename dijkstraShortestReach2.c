#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


int min(int a, int b) {
    return (a<b?a:b);
}

int minDistance(int sptSet[], int total, int dist[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 1; v <= total; v++) {
       if (sptSet[v] == 0 && dist[v] <= min) {
           min = dist[v]; 
           min_index = v;
       }
   }
     
 
   return min_index;
}

void printDist(int n, int start, int dist[]) {
    int i;
    for (i = 1; i <= n; i++) {
        if (i != start) {
             if (dist[i] == INT_MAX)
                 printf("-1 ");
             else
                 printf("%d ", dist[i]);
        }
    }
    printf("\n");
}

void dijkstra(int src, int V, int *graph[])
{
     int sptSet[V];
     int dist[V];

     for (int i = 1; i <= V; i++) {
         sptSet[i] = 0;
         dist[i] = INT_MAX;
     }

     dist[src] = 0;
 
     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(sptSet, V, dist);
       sptSet[u] = 1;

       for (int v = 1; v <= V; v++) {
           if (!sptSet[v] && graph[u][v] > 0 && dist[u] != INT_MAX 
                                       && dist[u]+  graph[u][v] < dist[v])
            dist[v] = dist[u] +  graph[u][v];
       }
         
     }
     printDist(V, src, dist);
}

void print(int *arr[], int n)
{
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
      
}

int main() {
    int t, n, m, i, j, e1, e2, start, weight;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        //printf("turn: %d nodes: %d edges: %d\n", t, n, m);
        int **graph = (int **)malloc((n+1) * sizeof(int *));;
        for (i=0; i<=n; i++)
            graph[i] = (int *)malloc((n+1) * sizeof(int));
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= n; j++) {
                graph[i][j] = 0;
            }
        }

                       
        for (i = 0; i < m; i++) {
            scanf("%d %d %d", &e1, &e2, &weight);
            
            if (graph[e1][e2] <= 0) {
                graph[e1][e2] = weight;
                graph[e2][e1] = weight;
            } else {
                graph[e1][e2] = min(graph[e1][e2], weight);
                graph[e2][e1] = min(graph[e2][e1], weight);
            }
            
        }
        /*
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                printf("%d ", graph[i][j]);
            }
            printf("\n");
        }
        */
        scanf("%d", &start);
        dijkstra(start, n, (int **)graph); 
        for (i = 0; i <= n; i++) { 
            free(graph[i]);
        }
        free(graph);
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
