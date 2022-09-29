// Problem Link :  https://lightoj.com/problem/digit-count

#include <bits/stdc++.h>
using namespace std;

int dp[10][10];

int solve(int idx, int prev, int n, int m, vector<int> &arr)
{
    if (idx == n)
        return 1;

    if (dp[idx][prev] != -1)
        return dp[idx][prev];

    int count = 0;
    for (int i = 0; i < m; i++)
    {
        if (prev == 0 || abs(prev - arr[i]) <= 2)
            count += solve(idx + 1, arr[i], n, m, arr);
    }

    return dp[idx][prev] = count;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> arr(m);

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < m; i++)
        cin >> arr[i];

    cout << solve(0, 0, n, m, arr);

    return 0;
}