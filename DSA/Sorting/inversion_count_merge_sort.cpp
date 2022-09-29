/*
Let A[0...n - 1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. Given n and an array A your task is to find the number of inversions of A.
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int n, int start, int mid, int end, int &count)
{
    vector<int> temp;
    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }

        else
        {
            temp.push_back(arr[right]);
            count += mid - left + 1;
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= end)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = start; i <= end; i++)
        arr[i] = temp[i - start];
}

void mergeSort(vector<int> &arr, int n, int start, int end, int &count)
{

    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, n, start, mid, count);
        mergeSort(arr, n, mid + 1, end, count);

        merge(arr, n, start, mid, end, count);
    }
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 3, 8, 6, 1};
    int ans = 0;
    mergeSort(arr, n, 0, n - 1, ans);
    cout << ans << "\n";

    return 0;
}