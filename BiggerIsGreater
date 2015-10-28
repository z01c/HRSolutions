#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int partition( char a[], int l, int r) {
   int pivot, i, j;
   char t;
   pivot = a[l];
   i = l; j = r+1;
		
   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}


void sortW(char word[], int to, int from)
{
  int j;
  if (to < from)
    {
      j = partition(word, to, from);
      sortW(word, to, j-1);
      sortW(word, j+1, from);
    }
}

int main() {
  int t, i,j, len, flg, k, l;
  char w[100], temp;
    scanf("%d", &t);
    while (t--) {
      flg = 0;
        k = 0;
        l = 0;
        scanf("%s", w);
        len = strlen(w);
		for (i = len - 1; i > 0; i--) {
	  if (w[i] > w[i-1]) {
	    k = i - 1;
	    flg = 1;
	    break;
	  }
	}
	for (j = len - 1; j > k; j--) {
	  if (w[j] > w[k]) {
	    l = j;
	    flg = 1;
	    break;
	  }
	}
	temp = w[l];
	w[l] = w[k];
	w[k] = temp;
	sortW(w,k+1, len-1);
	if (flg)
	  printf("%s\n", w);
	else
	  printf("no answer\n");
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
