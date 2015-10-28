#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char a[100001], b[100001];
        int occ[26];
        int hasSub = 0;
        for (int i = 0; i < 26; i++)
            occ[i] = 0;
        scanf("%s", &a);
        scanf("%s", &b);
        int len_a = strlen(a);
        for (int i = 0; i < len_a; i++) {
            occ[a[i]-97]++;
        }
        int len_b = strlen(b);
        for (int i = 0; i < len_b; i++) {
            if (occ[b[i]-97]) {
                hasSub = 1;
                break;
            }        
        }
        if (hasSub)
            printf("YES\n");
        else
            printf("NO\n");
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
