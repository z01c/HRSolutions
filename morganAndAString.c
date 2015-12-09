#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char jacksLetters[100001];
char danysLetters[100001];
int ptrJ, ptrD;

int min (int x, int y) {
    if (x < y)
        return x;
    return y;
}

char resolve(int a, int b, int c, int d) {
    char* toJacks = jacksLetters;
    char* toDanys = danysLetters;
    int rem = min(a-c, b-d);
    if (!rem) {
        if (a-c) {
            ptrJ++;
            return jacksLetters[c];
        } else {
            ptrD++;
            return danysLetters[d];
        }             
    }
    if (strncmp(toJacks+c, toDanys+d, rem) < 0) {
        ptrJ++;
        return jacksLetters[c];
    }        
    else {
        ptrD++;
        return danysLetters[d];
    }        
}

int main() {
    int t, i, lenJ, lenD, lenR;
    scanf("%d", &t);
    while (t--) {
        for (i = 0; i < 100001; i++) {
            jacksLetters[i] = danysLetters[i] = '\0';
        }
        char result[200004];
        for (i = 0; i < 200004; i++)
            result[i] = '\0';
        scanf("%s", jacksLetters);
        scanf("%s", danysLetters);
        lenJ = strlen(jacksLetters);
        lenD = strlen(danysLetters);
        
        jacksLetters[lenJ] = 'z';
        jacksLetters[lenJ+1] = '\0';
        danysLetters[lenD] = 'z';
        danysLetters[lenD+1] = '\0';
        
        lenJ = strlen(jacksLetters);
        lenD = strlen(danysLetters);
        lenR = lenJ + lenD;
        ptrJ = ptrD = 0;
        for(i = 0; i < lenR - 2; i++) {
            result[i] = resolve(lenJ, lenD, ptrJ, ptrD);
        }
        printf("%s\n", result);
    }
    return 0;
}
