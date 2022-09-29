//  Subarray: Continuous part of the array.
//  Number of subarrays of an array with n elements  = nC2 + n = n*(n+1)/2.
//  Subsequence: A Subsequence is a sequence that can be derived an array by selecting zero or more elements,
//  without changing the order of the remaining elements.
//  Number of Subsequences of an array with n elements = 2^n.
//  Quote:  Every Subarray is a Subsequence but Subsequence is not a Subarray.

// sum of all possible Subarray
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d ", &arr[i]);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            printf("%d ", sum);
        }
    }

    return 0;
}