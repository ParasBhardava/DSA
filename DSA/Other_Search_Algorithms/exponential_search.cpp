#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int key)
{
    while(start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
            return mid;

        if (key < arr[mid])
            end = mid - 1;

        else
            start = mid + 1;
    }

    return -1;
}

int exponentialSearch(int arr[], int n, int key)
{
    if (arr[0] == key)
        return 0;

    int i = 1;

    while (i < n && arr[i] <= key)
        i = i * 2;

    return binarySearch(arr, i / 2, min(i, n-1), key);
}

int main(void)
{
    int n = 5;
    int arr[] = {2, 3, 4, 10, 40};
    int key = 10;
    int result = exponentialSearch(arr, n, key);

    if (result == -1)
        printf("Element is not present in array");

    else
        printf("Element is present at index %d", result);

    return 0;
}


// Time complexity : O(logN)
// For exponential search given array is sorted
// useful for unbounded array(size of array is infinite)
// in works better than binary search