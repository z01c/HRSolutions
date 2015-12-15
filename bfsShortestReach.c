#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 1001

int GRAPH[MAX][MAX] = {{-1}};
int DIST[MAX] = {0};
int edge_length = 6;
int queue_array[MAX];
int rear = - 1;
int front = - 1;

void enqueue(int add_item) {
    if (front == - 1)
        front = 0;
    rear++;
    queue_array[rear] = add_item;
}

int dequeue() {
    if (front == - 1 || front > rear) 
        return -1;
    front++;
    return queue_array[front-1];
}

int isEmpty() {
    if (front == - 1 || front > rear)
        return 1;
    else
        return 0;
}

int min(int a, int b) {
    return (a<b?a:b);
}

void do_BFS(int start_node, int total_nodes) {
    int visited[total_nodes];
    int i, current_node;
    for (i = 1; i <= total_nodes; i++) {
        visited[i] = 0;
    }
    rear = - 1;
    front = - 1;
    visited[start_node] = 1;
    enqueue(start_node);
    while (!isEmpty()) {
        current_node = dequeue();
        for (i = 1; i <= total_nodes; i++) {
            if (GRAPH[current_node][i] > 0) {
                if (!visited[i]) {
                    visited[i] = 1;
                    DIST[i] = min(DIST[i], DIST[current_node] + edge_length);
                    //printf("At node %d: Edge %d to %d: DIST[%d] = %d, DIST[%d] = %d\n", i, current_node, i, i, DIST[i], current_node, DIST[current_node]);
                    enqueue(i);                    
                }
            }
        }
    }    
}

int main() {
    int t, n, m, i, j, e1, e2, start;
    scanf("%d", &t);
    //printf("INT_MAX = %d\n", INT_MAX);
    while (t--) {
        scanf("%d %d", &m, &n);
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= m; j++) {
                GRAPH[i][j] = -1;
            }
        }
        for (i = 1; i <= m; i++)
            DIST[i] = INT_MAX;
        for (i = 0; i < n; i++) {
            scanf("%d %d", &e1, &e2);
            GRAPH[e1][e2] = edge_length;
            GRAPH[e2][e1] = edge_length;
        }
        scanf("%d", &start);
        DIST[start] = 0;
        do_BFS(start, m);
        for (i = 1; i <= m; i++) {
            if (i != start) {
                if (DIST[i] == INT_MAX)
                    printf("-1 ");
                else
                    printf("%d ", DIST[i]);
            }
        }
        printf("\n");            
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
