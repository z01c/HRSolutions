#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, m, i, j, num;
    int A[1000011], B[1000011], X[10001];
    for (i = 1; i <= 10000; i++)
        X[i] = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        A[i] = num;
        X[num]--;
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &num);
        B[i] = num;
        X[num]++;
    }
    for (i = 1; i <= 10000; i++) {
        if (X[i] > 0)
            printf("%d ", i);
    }
    return 0;
}
