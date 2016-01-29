#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isPowerOfTwo(unsigned long long int n) {
    if (n) {
        if (n & (n-1))
            return 0;
        else
            return 1;
    }
    return 0;
}

unsigned long long int prevMaxPowOfTwo(unsigned long long int x) {
   x = x | (x >> 1);
   x = x | (x >> 2);
   x = x | (x >> 4);
   x = x | (x >> 8);
   x = x | (x >>16);
   x = x | (x >>32);
   return x - (x >> 1);
}

int main() {
    int t;
    unsigned long long int n;
    scanf("%d", &t);
    while (t--) {
        scanf("%llu", &n);
        int turn = 0;
        while (n > 1) {
            if (isPowerOfTwo(n)) {
                n = n/2;
            } else {
                n = n - prevMaxPowOfTwo(n);
            }
            turn++;
        }
        if (turn%2)
            printf("Louise\n");
        else
            printf("Richard\n");
    }
    return 0;
}
