#include <bits/stdc++.h>
using namespace std;

int solve(int n, int sum, vector<int> &arr)
{
    vector<int> prev(sum + 1, 0);
    vector<int> curr(sum + 1, 0);
    prev[0] = curr[0] = 1;

    if (arr[0] <= sum)
        prev[arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int dontTake = prev[j];
            int take = 0;

            if (arr[i] <= j)
                take = prev[j - arr[i]];

            curr[j] = take + dontTake;
        }

        prev = curr;
    }

    return prev[sum];
}

int main()
{
    int n = 4;
    vector<int> arr = {1, 2, 3, 3};
    int sum = 6;

    cout << solve(n, sum, arr) << "\n";
    return 0;
}