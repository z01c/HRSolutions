#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int L[5001][5001];

int max(int a, int b)
{
    return (a > b)? a : b;
}

int lcs( char *X, char *Y, int m, int n )
{
   
   int i, j;

   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   return L[m][n];
}

int main() {
    char inp1[5001];
    char inp2[5001];
    int len1, len2;
    scanf("%s", inp1);
    scanf("%s", inp2);
    len1 = strlen(inp1);
    len2 = strlen(inp2);
    printf("%d\n", lcs(inp1, inp2, len1, len2));
    return 0;
}
