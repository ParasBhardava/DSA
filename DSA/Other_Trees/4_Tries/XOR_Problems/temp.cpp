#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &arr, int mid, int sum)
{
    int total = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        total += arr[i] / mid;
        if (total > sum)
            return false;
    }

    return total <= sum;
}

int main()
{
    int n = 7, sum = 10;
    vector<int> arr = {2, 3, 5, 8, 11, 13, 16};

    int start = 1, end = *max_element(arr.begin(), arr.end()), mid, ans;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (solve(arr, mid, sum))
        {
            ans = mid;
            end = mid - 1;
        }

        else
            start = mid + 1;
    }

    cout << ans << "\n";
    return 0;
}