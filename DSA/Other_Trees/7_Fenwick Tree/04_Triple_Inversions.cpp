// i < j < k and ai > aj > ak
// Problem Link : https://www.spoj.com/problems/TRIPINV/

#include <bits/stdc++.h>
using namespace std;

class FWTree
{
    int n;
    vector<int> fenweek;

public:
    FWTree(int size)
    {
        n = size;
        fenweek.resize(n + 1);
    }

    void update(int idx, int val)
    {
        while (idx <= n)
        {
            fenweek[idx] += val;
            idx = idx + (idx & ~(idx - 1));
        }
    }

    int sum(int idx)
    {
        int s = 0;
        while (idx > 0)
        {
            s += fenweek[idx];
            idx = idx - (idx & ~(idx - 1));
        }

        return s;
    }
};

int main()
{
    int n;
    cin >> n;
    FWTree ft1(n);
    FWTree ft2(n);
    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        ft1.update(arr[i], 1);
    }

    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        ft1.update(arr[i], -1);
        int c1 = ft1.sum(arr[i] - 1);
        int c2 = ft2.sum(n) - ft2.sum(arr[i]);
        ft2.update(arr[i], 1);

        cout << c1 << " " << c2 << "\n";
        count += c1 * c2;
    }

    cout << count;

    return 0;
}