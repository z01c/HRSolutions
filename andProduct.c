#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int hibit(unsigned int n) {
    n |= (n >>  1);
    n |= (n >>  2);
    n |= (n >>  4);
    n |= (n >>  8);
    n |= (n >> 16);
    return n - (n >> 1);
}


unsigned int andInRange(unsigned int n, unsigned int m) {
    int dif = m-n;
    int p = (int) log2((int) dif);
    if (pow(2,p) != dif)
        p++;
    int d = pow(2, p)-1;
    return n&m&(0xFFFFFFFF^d);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        unsigned int a, b;
        scanf("%u%u", &a, &b);
        if (a == 0)
            printf("0\n");
        else if(hibit(a) == hibit(b))
            printf("%u\n", andInRange(a,b));
        else
            printf("0\n");
    }
    return 0;
}
