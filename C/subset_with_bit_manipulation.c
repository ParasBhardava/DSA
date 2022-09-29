#include<stdio.h>

void subset(int arr[], int n)
{
    for(int i =0; i<(1<<n); i++)
    {
        printf("{");
        for(int j =0; j<n;j++)
        {
            if( (i&(1<<j)) != 0)
            printf(" %d ", arr[j]);
        }
        printf("}");
        printf("\n");
    }
}

int main()
{
   int n;
   scanf("%d", &n);
   int arr[n];
   for(int i= 0; i<n; i++)
   {
       scanf("%d", &arr[i]);
   }

   subset(arr, n);

   return 0; 
}

// Time complexity
// using bit manipulation : O(n * (2^n));
// using recursion: O(2^n);