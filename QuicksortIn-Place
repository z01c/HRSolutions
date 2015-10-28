#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int partition(int * ar, int low, int high, int ar_size) {
    int pivot = ar[high];
    int i = low;
    int j, temp, k;
    for (j = low; j < high; j++) {
        if (ar[j] <= pivot) {
            temp = ar[i];
            ar[i] = ar[j];
            ar[j] = temp;
            i++;
        }
    }
    temp = ar[i];
    ar[i] = ar[high];
    ar[high] = temp;
    for (k = 0; k < ar_size; k++)
        printf("%d ", ar[k]);
    printf("\n");
    return i;
}

void quickSort(int *ar, int low, int high, int ar_size) {
    int p;
    if (low < high) {
        p = partition(ar,low,high, ar_size);
        quickSort(ar, low, p-1, ar_size);
        quickSort(ar, p+1, high, ar_size);
    }
}

int main() {
   int ar_size;
   scanf("%d", &ar_size);
   int ar[ar_size], i;
   for(i = 0; i < ar_size; i++) { 
      scanf("%d", &ar[i]); 
   }
   quickSort(ar, 0, ar_size-1, ar_size);  
    return 0;
}
