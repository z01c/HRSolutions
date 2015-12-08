#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 26

int isAnagram(char *str1, char *str2) {
    int count1[MAX] = {0};
    int count2[MAX] = {0};
    int i;
    for (i = 0; str1[i] && str2[i];  i++)
    {
        count1[str1[i] - 97]++;
        count2[str2[i] - 97]++;
    }
    if (str1[i] || str2[i])
      return 0;
    for(int i = 0; i < MAX; i++) {
        //printf("i: %d, count1 at i: %d, count2 at i: %d\n", i, count1[i], count2[i]);
        if(count1[i] != count2[i])
            return 0;
    }
    //printf("Inside isAnagram: %s and %s\n", str1, str2);
    return 1;
}

int main() {
    int t, len, cnt, i, j, k;
    char inp[101];
    scanf("%d", &t);
    while (t--) {
        cnt = 0;
        scanf("%s", inp);
        len = strlen(inp);
        //printf("len: %d\n", len);
        if (len < 2) {
            printf("%d\n", cnt);
        }
        else {
            // first search for 1 letter anagrams
            for (i = 0; i < len-1; i++) {
                for (j = i+1; j < len; j++) {
                    if (inp[i] == inp[j])
                        cnt++;
                }
            }
            // search among 2, 3 ... (len-1) letter pairs
            for (k = 2; k <= len-1; k++) {
                char sub1[k+1], sub2[k+1];
                for (i = 0; i < len-k; i++) {
                    for (j = i+1; j <= len -k; j++) {
                        memcpy( sub1, &inp[i], k );
                        sub1[k] = '\0';
                        //printf("sub1: %s\n", sub1);
                        memcpy( sub2, &inp[j], k );
                        sub2[k] = '\0';
                        //printf("sub2: %s\n", sub2);
                        if (isAnagram(sub1, sub2)) {
                            cnt++;
                            //printf("anagram: %s and %s\n", sub1, sub2);
                        }
                            
                        
                    }
                    
                }
            }
            
        }
        printf("%d\n", cnt);
    }
    return 0;
}
