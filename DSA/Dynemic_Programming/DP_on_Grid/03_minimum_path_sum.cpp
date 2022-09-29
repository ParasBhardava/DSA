/*
Given a n x m grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[0][0];

    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = grid[i][j] + minPathSum(grid, i - 1, j, dp);
    int left = grid[i][j] + minPathSum(grid, i, j - 1, dp);

    return dp[i][j] = min(up, left);
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << minPathSum(grid, n - 1, m - 1, dp);

    return 0;
}
