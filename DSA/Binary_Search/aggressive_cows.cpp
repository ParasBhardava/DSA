#include <bits/stdc++.h>
using namespace std;

bool solve(int dist, int arr[], int n, int cows)
{
    int count = 1;
    int prevCow = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - prevCow >= dist)
        {
            count++;
            prevCow = arr[i];
        }

        if (count == cows)
            return true;
    }

    return false;
}

int main()
{
    int n = 5;
    int arr[] = {1, 2, 4, 8, 9};
    int cows = 3;

    sort(arr, arr + n);
    int start = 1, end = arr[n - 1] - arr[0], mid, ans;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (solve(mid, arr, n, cows))
        {
            ans = mid;
            start = mid + 1;
        }

        else
            end = mid - 1;
    }

    cout << ans << "\n";

    return 0;
}