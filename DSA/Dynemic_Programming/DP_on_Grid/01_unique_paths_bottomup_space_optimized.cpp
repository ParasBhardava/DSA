#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m)
{
    vector<int> prev(m, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = 1;

            else
            {
                int up = 0;
                int left = 0;

                if (i > 0)
                    up = prev[j];

                if (j > 0)
                    left = curr[j - 1];

                curr[j] = up + left;
            }
        }

        prev = curr;
    }

    return prev[m - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << solve(n, m) << "\n";
    return 0;
}

/*

_____________
| s |   |   |
|   |   |   |
|   |   | e |
-------------

*/