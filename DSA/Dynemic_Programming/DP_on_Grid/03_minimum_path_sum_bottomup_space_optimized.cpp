#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = grid[i][j];

            else
            {
                int up = grid[i][j];
                int left = grid[i][j];

                if (i > 0)
                    up += prev[j];
                else
                    up += 1e9;

                if (j > 0)
                    left += curr[j - 1];
                else
                    left += 1e9;

                curr[j] = min(up, left);
            }
            prev = curr;
        }
    }

    return prev[m - 1];
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};

    cout << minPathSum(grid);

    return 0;
}
