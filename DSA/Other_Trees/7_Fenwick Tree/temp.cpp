#include <bits/stdc++.h>
using namespace std;

class FWTree
{
    int main()
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        vector<vector<int>> operations(m + 1);
        for (int i = 1; i <= m; i++)
        {
            int l, r, d;
            cin >> l >> r >> d;
            operatins[i] = {l, r, d};
        }

        return 0;
    }