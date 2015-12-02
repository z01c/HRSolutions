#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 101

char MAP[MAX][MAX];
int visited[MAX][MAX];

struct node{
    int x;
    int y;
    struct node *pre;
};
    
void makeRoute(int x, int y, struct node *head, struct node *tail, int mapW, int mapH) {
    if (x < 0 || y < 0 || x >= mapW || y >= mapH || visited[x][y])
        return;
    if (MAP[x][y] == 'X')
        return;
    if (MAP[x][y] == '*') {
        tail->pre = head;
        return;
    }
    visited[x][y] = 1;
    struct node * aNode = (struct node*) malloc(sizeof(struct node));
    aNode->x = x;
    aNode->y = y;
    aNode->pre = head;
    makeRoute(x-1, y, aNode, tail, mapW, mapH);
    makeRoute(x+1, y, aNode, tail, mapW, mapH);
    makeRoute(x, y-1, aNode, tail, mapW, mapH);
    makeRoute(x, y+1, aNode, tail, mapW, mapH);
}

int countK(struct node *tail) {
    int count = 0;
    struct node *ptr = tail;
    if (ptr->pre)
        ptr = ptr->pre;
    else
        return count;
    while(ptr) {
        int x = ptr->x;
        int y = ptr->y;
        //printf("visiting %d %d\n", x, y);
        int possibleRoute = 0;
        if ((MAP[x-1][y] == '.' || MAP[x-1][y] == 'M') && visited[x-1][y] == 0)
            possibleRoute++;
        if ((MAP[x+1][y] == '.' || MAP[x+1][y] == 'M') && visited[x+1][y] == 0)
            possibleRoute++;
        if ((MAP[x][y-1] == '.' || MAP[x][y-1] == 'M') && visited[x][y-1] == 0)
            possibleRoute++;
        if ((MAP[x][y+1] == '.' || MAP[x][y+1] == 'M') && visited[x][y+1] == 0)
            possibleRoute++;
        if (possibleRoute > 1 || (possibleRoute > 0 && MAP[x][y] == 'M')) {
            count++;
            //printf("Increasing count(%d) at %d %d with %d possible route\n", count, x, y, possibleRoute);
        }
            //count++;
        visited[x][y] = 1;
        ptr = ptr->pre;
    }
    return count;
}

void resetVisited() {
    int i, j;
    for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                visited[i][j] = 0;
            }
        }
}

int main() {
    int t,n,m,i,j,k, her_x, her_y, des_x,des_y, k_count;
    char c;
    scanf("%d", &t);
    while (t--) {
        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                MAP[i][j] = 'X';
                visited[i][j] = 0;
            }
        }
        k_count = 0;
        scanf("%d %d", &n, &m);
        //printf("%d %d\n", n, m);
        //resetQ(n, m);
        for (i = 0; i < n; i++) {
           scanf("%s", MAP[i]);
        }
        scanf("%d", &k);
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (MAP[i][j] == 'M') {
                    her_x = i;
                    her_y = j;
                }
                if (MAP[i][j] == '*') {
                    des_x = i;
                    des_y = j;
                }
            }
        }
        struct node * tail = (struct node*) malloc(sizeof(struct node));
        tail->x = des_x;
        tail->y = des_y;
        /*struct node *head = (struct node*) malloc(sizeof(struct node));
        head->x = her_x;
        head->y = her_y;
        head->pre = NULL;*/
        makeRoute(her_x, her_y, NULL, tail, n, m);
        resetVisited();
        k_count = countK(tail);
        //printf("k_count: %d\n", k_count);
        if (k_count == k)
            printf("Impressed\n");
        else
            printf("Oops!\n");
    }
    return 0;
}
