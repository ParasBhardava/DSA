#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    vector<int> arr = {4, 7, 1, 9, 2, 12, 8, 3, 24, 5};

    int size = log2(n) + 1;
    int sparse[n][size] = {0};

    for (int j = 0; j < size; j++)
    {
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            if (j == 0)
                sparse[i][j] = arr[i];

            else
                sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int len = log2(r - l + 1);
        cout << min(sparse[l][len], sparse[r - (1 << len) + 1][len]) << "\n";
    }

    return 0;
}