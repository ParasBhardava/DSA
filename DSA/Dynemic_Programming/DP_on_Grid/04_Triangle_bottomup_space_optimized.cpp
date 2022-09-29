#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> next(n, 0);

    for (int j = 0; j < n; j++)
        next[j] = triangle[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> curr(n, 0);
        for (int j = i; j >= 0; j--)
        {
            int d = triangle[i][j] + next[j];
            int dg = triangle[i][j] + next[j + 1];

            curr[j] = min(d, dg);
        }

        next = curr;
    }

    return next[0];
}

int main()
{
    vector<vector<int>> triangle = {{2},
                                    {3, 4},
                                    {6, 5, 7},
                                    {4, 1, 8, 3}};

    cout << minimumTotal(triangle);

    return 0;
}