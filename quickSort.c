#include <stdio.h> 
#include<ctype.h>
void swapping(int* x, int* y) 
{ 
int temp = *x; 
*x = *y; 
*y = temp; 
}
void qksrtalgo(int array[], int p, int r) 
{ 
if(p < r) 
{ 
int q; 
q = partition_function(array, p, r); 
qksrtalgo(array, p, q-1);
qksrtalgo(array, q+1, r); 
} 
} 
int partition_function (int array[], int first, int last) 
{ 
int pivotelement = array[last];
int i = (first - 1);
for (int j = first; j <= last- 1; j++) 
{
if (array[j] <= pivotelement) 
{ 
i++;
swapping(&array[i], &array[j]); 
} 
} 
swapping(&arr[i + 1], &arr[last]);
return (i + 1);
}
void quicklysortedarray(int array[], int sizeofarray) 
{ 
int i; 
for (i=0; i < sizeofarray; i++) 
{ 
printf("%d ", array[i]); 
} 
printf("\n"); 
}
int main() 
{ 
int array[] = {10, 11, 8, 12, 6, 1, 13, 2, 5, 3}; 
int n = sizeof(array)/sizeof(array[0]);
qksrtalgo(arr, 0, n-1); 
printf("Array has been sorted for n values"); 
quicklysortedarray(arr, n); 
return 0; 
}
