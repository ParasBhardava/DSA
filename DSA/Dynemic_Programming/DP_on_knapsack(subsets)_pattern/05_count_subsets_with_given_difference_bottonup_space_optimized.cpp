#include <bits/stdc++.h>
using namespace std;

int solve(int n, int sum, vector<int> &arr)
{
    vector<int> prev(sum + 1, 0);
    vector<int> curr(sum + 1, 0);

    if (arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if (arr[0] != 0 && arr[0] <= sum)
        prev[arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int dontTake = prev[j];
            int take = 0;

            if (arr[i] <= j)
                take = prev[j - arr[i]];

            prev[j] = take + dontTake;
        }
    }

    return prev[sum];
}

int main()
{
    int n = 4;
    vector<int> arr = {5, 2, 6, 4};
    int diff = 3;

    int sum = accumulate(arr.begin(), arr.end(), 0);
    int ans;
    if (sum - diff < 0 || (sum - diff) % 2 == 1)
        ans = 0;

    else
    {
        ans = solve(n - 1, (sum - diff) / 2, arr);
    }

    cout << ans << "\n";

    return 0;
}