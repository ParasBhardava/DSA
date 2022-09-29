#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int length, vector<int> &price, vector<vector<int>> &dp)
{
    if (idx == 0)
        return price[0] * length;

    if (dp[idx][length] != -1)
        return dp[idx][length];

    int dontTake = solve(idx - 1, length, price, dp);

    int take = INT_MIN;
    int currLenght = idx + 1;
    if (length - currLenght >= 0)
        take = price[idx] + solve(idx, length - currLenght, price, dp);

    return dp[idx][length] = max(take, dontTake);
}

int main()
{
    int n = 8;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << solve(n - 1, n, price, dp);

    return 0;
}