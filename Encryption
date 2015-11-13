#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isPerfectSquare(int n) {
    int a = sqrt(n);
    if (a*a == n)
        return 1;
    return 0;
}

int main() {
    char input[82] = "";
    char rect[10][10];
    int  rectW, rectH;
    int alt = 1;
    scanf("%s", input);
    //printf("input: %s\n", input);
    int len = strlen(input);
    //printf("length: %d\n", len);
    rectW = floor(sqrt(len));
    rectH = ceil(sqrt(len)) - 1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            rect[i][j] = '\0';
        }
    }
    //printf("before: %d %d %d\n", len, rectW, rectH);
    if (isPerfectSquare(len)) {
        rectH = rectW = sqrt(len);
    }
    else {
    while (rectH * rectW < len) {
        if (alt) {
            rectW++;
            alt = !alt;
        }
        else {
            rectH++;
            alt = !alt;
        }
    }
    }
    //printf("after: %d %d %d\n", len, rectW, rectH);
    //rectW = rectH = 4;
    int k = 0;
    for (int i = 0; i < rectH; i++) {
        for (int j = 0; j < rectW; j++) {
            rect[i][j] = input[k];
            //printf("%c", input[k]);
            k++;
        }
        //printf("\n");
    }
    for (int j = 0; j < rectW; j++){
        int i = 0;
        while(rect[i][j]) {
            //printf("%c %d %d   ", rect[i][j], i, j);
            printf("%c", rect[i][j]);
            i++;
        }
        //printf("\n");
        printf(" ");
    }
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
