#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int calculate(char str[])
{
    int counts[26];
    int i, med1, med2, cntmed1, cntmed2;
    int len = strlen(str);
    for (i = 0; i < 26; i++)
        counts[i] = 0;
    for (i = 0; i < len; i++) {
        counts[str[i] - 97]++;
    }
    med1 = med2 = cntmed1 = cntmed2 = 0;
    for (i = 0; i < 26; i++) {
        if (counts[i]) {
            if (cntmed1) {
                if (med1 == counts[i])
                    cntmed1++;
                else if (!cntmed2) {
                    med2 = counts[i];
                    cntmed2++;
                }
                else if (cntmed2) {
                    if (med2 == counts[i])
                        cntmed2++;
                    else
                        return 0;  
                        // 3 kinds of value in counts array mean it's not possible to remove 1 char to make it valid string
                }
            }
            if (!cntmed1) {
                med1 = counts[i];
                cntmed1++;
            }
            
        }
    }
    if (cntmed1 && cntmed2) {
        if (cntmed1 > 1 && cntmed2 > 1)
            return 0; 
        if (cntmed1 > cntmed2) {
            if (cntmed2 > 1)
                return 0;
            else
                return 1;
        }
        else if (cntmed1 < cntmed2) {
            if (cntmed1 > 1)
                return 0;
            else
                return 1;
        }
        else {
            if (cntmed1 == 1 && cntmed2 == 1)
                return 1;
            else
                return 0;
        }
    }
    return 1;
}

int main() {
    char inp[100001];
    scanf("%s", inp);
    if (calculate(inp))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
