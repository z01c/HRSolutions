#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define XMAX 101

int helper[XMAX] = {0};

struct input{
    int val;
    char text[11];
};

int main() {
    int n, i;
    scanf("%d", &n);
    struct input inputs[n];
    struct input results[n];
    int inpVal, idx;
    char inpStr[11];
    for (i = 0; i < n; i++) {
        scanf("%d%s", &inpVal, inpStr);
        inputs[i].val = inpVal;
        helper[inpVal]++;
        if (i >= n/2)
            strcpy(inputs[i].text, inpStr);
        else
            strcpy(inputs[i].text, "-");
    }
    int sum = 0;
    for (i = 0; i < XMAX; i++) {
        sum += helper[i];
        helper[i] = sum;
    }
    for (i = n-1; i >= 0; i--) {
        idx = inputs[i].val;
        helper[idx]--;
        results[helper[idx]] = inputs[i];
    }
    for (i = 0; i < n; i++) {
        printf("%s ", results[i].text);
    }
    return 0;
}
