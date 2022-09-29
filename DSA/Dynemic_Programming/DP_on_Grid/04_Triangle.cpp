#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp)
{
    int n = triangle.size();
    if (i == n - 1)
        return triangle[n - 1][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int d = triangle[i][j] + minimumTotal(triangle, i + 1, j, dp);
    int dg = triangle[i][j] + minimumTotal(triangle, i + 1, j + 1, dp);

    return dp[i][j] = min(d, dg);
}

int main()
{
    vector<vector<int>> triangle = {{2},
                                    {3, 4},
                                    {6, 5, 7},
                                    {4, 1, 8, 3}};

    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << minimumTotal(triangle, 0, 0, dp);

    return 0;
}