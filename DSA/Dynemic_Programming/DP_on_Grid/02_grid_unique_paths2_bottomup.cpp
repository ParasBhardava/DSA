#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                dp[i][j] = 0;

            else if (i == 0 && j == 0)
                dp[i][j] = 1;

            else
            {
                int up = 0;
                int left = 0;

                if (i > 0)
                    up = dp[i - 1][j];

                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = left + up;
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 0},
                                {0, 1, 0},
                                {0, 0, 0}};

    cout << uniquePathsWithObstacles(grid);

    return 0;
}
