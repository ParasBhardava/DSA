#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m, 0), curr(m, 0);

    for (int j = 0; j < m; j++)
        prev[j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = matrix[i][j] + prev[j];

            int ld = matrix[i][j];
            if (j - 1 >= 0)
                ld += prev[j - 1];
            else
                ld += -1e8;

            int rd = matrix[i][j];
            if (j + 1 < m)
                rd += prev[j + 1];
            else
                rd += -1e8;

            curr[j] = max(u, max(ld, rd));
        }

        prev = curr;
    }

    int maxi = -1e8;
    for (int j = 0; j < m; j++)
        maxi = max(maxi, prev[j]);

    return maxi;
}

int main()
{
    vector<vector<int>> matrix = {{2, 1, 3},
                                  {6, 5, 4},
                                  {7, 8, 9}};

    cout << solve(matrix) << "\n";
}