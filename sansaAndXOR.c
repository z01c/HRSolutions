#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int numbers[n];
        int number, result;
        for (int i = 0; i < n; i++) {
            scanf("%d", &number);
            numbers[i] = number;
        }
        result = 0;
        if (n%2) {
            for (int i = 0; i < n; i++) {
                if (i%2 == 0) {
                    result = result ^ numbers[i];
                }
            }
            printf("%d\n", result);
        } else {
            printf("%d\n", result);
        }
    }
   
    return 0;
}
