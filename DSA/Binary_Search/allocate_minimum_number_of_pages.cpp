#include <bits/stdc++.h>
using namespace std;

bool isValid(int arr[], int n, int k, int max)
{
    int sum = 0, students = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > max)
        {
            students++;
            sum = arr[i];
        }

        if (students > k)
            return false;
    }

    return true;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int k = 2, n = 4;

    if (n < k)
    {
        cout << -1 << "\n";
        return 0;
    }

    int end = 0, start = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        end += arr[i];
        start = max(start, arr[i]);
    }

    int mid, res = -1;
    while (start <= end)
    {
        mid = end + ((start - end) / 2);

        if (isValid(arr, n, k, mid))
        {
            res = mid;
            end = mid - 1;
        }

        else
            start = mid + 1;
    }

    cout << res << "\n";

    return 0;
}