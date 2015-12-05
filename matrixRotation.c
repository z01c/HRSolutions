#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void rotate(int height, int width, int mtrx[][width], int rotation) {
    int i, j, k, l, m, n, tmpval, rr, hrc, wrc;
    k = l = 0;
    hrc = height;
    wrc = width;
    while (hrc > 1 && wrc > 1) {
        rr = rotation % (2 * (hrc + wrc) - 4);
        tmpval = 0;
        while (rr--) {
            tmpval = mtrx[k][l];
            for (i = k, j = l; j < width-1-l; j++) {
                mtrx[i][j] = mtrx[i][j+1];
                m = i;
                n = j + 1;
            }
            for (i = m, j = n; i < height-1-k; i++) {
                mtrx[i][j] = mtrx[i+1][j];
                m = i + 1;
                n = j;
            }
            for (i = m, j = n; j > l; j--) {
                mtrx[i][j] = mtrx[i][j-1];
                m = i;
                n = j - 1;
            }
            for (i = m, j =n; i > k; i--) {
                mtrx[i][j] = mtrx[i-1][j];
            }
            mtrx[k+1][l] = tmpval;
        }
        hrc = hrc - 2;
        wrc = wrc - 2;
        k++;
        l++;
    }
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++ ) {
            printf("%d ", mtrx[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int h, w, i, j, r, rr;
    scanf("%d", &h);
    scanf("%d", &w);
    scanf("%d", &r);
    int m[h][w];
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    //rr = r % (2 * (h + w) - 4);
    rotate(h, w, m, r);
    return 0;
}
