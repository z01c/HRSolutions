/* Sample program illustrating input/output methods */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int partition( int a[], int l, int r) {
   int pivot, i, j;
   int t;
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


void sortW(int word[], int to, int from)
{
  int j;
  if (to < from)
    {
      j = partition(word, to, from);
      sortW(word, to, j-1);
      sortW(word, j+1, from);
    }
}

int main(){

//Helpers for input/output
   int i, N, K;
   int C[102];
   
   scanf("%d %d", &N, &K);
   for(i=0; i<N; i++){
      scanf("%d", &(C[i]));
   }
   
   sortW(C, 0, N-1);
   int result = 0;
    int x = 0;
    int j = 0;
   for(i=N-1; i>=0; i--){
      result = result + (x + 1) * C[i];
       j++;
       if(j == K) {
           x++;
           j = 0;
       }
   }
   
   printf("%d\n", result);

}
