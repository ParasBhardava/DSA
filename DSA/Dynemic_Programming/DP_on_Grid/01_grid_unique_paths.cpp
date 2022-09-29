#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = uniquePaths(i - 1, j, dp);
    int left = uniquePaths(i, j - 1, dp);
    return dp[i][j] = up + left;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << uniquePaths(n - 1, m - 1, dp) << "\n";
    return 0;
}
