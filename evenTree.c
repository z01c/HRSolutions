#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int m, n, i, j, child, parent, count;
    int edges[101][101], val[101], input[101][2];
    for (i = 1; i <= 100; i++)
        val[i] = 0;
    for (i = 1; i <= 100; i++)
        for (j = 1; j <= 100; j++) {
        edges[i][j] = 0;
    }
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d%d\n", &input[i][0], &input[i][1]);
        child = input[i][0];
        parent = input[i][1];
        edges[parent][child] = 1;
    }
    for (i = 1; i <= n; i++) {
        count = 1;
        for (j = 1; j <=n; j++) {
            if (edges[i][j])
            count++;
        }
        val[i] = count;          
    }
    for (i = m-1; i >= 0; i--) {
        if (val[input[i][0]] > 1)
          val[input[i][1]] = val[input[i][1]] + val[input[i][0]] - 1;
    }
    /*for (i = 1; i <= n; i++)
        printf("%d ", val[i]);*/
    count = 0;
    for (i = 2; i <= n; i++) {
        if (val[i] % 2 == 0)
            count++;
    }
    printf("%d", count);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
