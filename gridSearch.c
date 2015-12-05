#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char bGr[1005][1005];
char sGr[1005][1005];
char* bRow;
char* sRow;

int matPat (int i, int j, int k, int row, int column) {
    char* bGrid = bGr[i];
    char* sGrid = sGr[k];
    if (k == row)
        return 1;
    while (k < row) {
        if (!strncmp(bGrid+j, sGrid, column)) {
            i++;
            k++;
            bGrid = bGr[i];
            sGrid = sGr[k];
        } else {
            return 0;
        }
    }   
    return 1;
}

int main() {
    int t, R, C, r, c, i, j, k, l, m_flag;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &R, &C);
        for (i = 0; i < R; i++) {
            scanf("%s", bGr[i]);
        }
        scanf("%d%d", &r, &c);
        for (i = 0; i < r; i++) {
            scanf("%s", sGr[i]);
        }
        i = j = k = l = 0;
        m_flag = 0;
        sRow = sGr[k];
        for (i = 0; i <= R-r; i++) {
            if (m_flag)
                break;
            bRow = bGr[i];
            for (j = 0; j <= C-c; j++) {
                if (!strncmp(bRow+j, sRow, c)) {
                    //printf("%s\n%s\n", bRow+j, sRow);
                    if (matPat(i+1, j, k+1, r, c)) {
                        printf("YES\n");
                        m_flag = 1;
                        break;
                    }                    
                }
            }
        }
        if (!m_flag)
           printf("NO\n");
    }
    return 0;
}
