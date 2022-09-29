// Problem Link : https://codeforces.com/problemset/problem/61/E

#include <bits/stdc++.h>
using namespace std;

class FWTree
{
    int n = 1000001;
    vector<int> fenweek;

public:
    FWTree()
    {
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

void coordinateCompression(vector<int> &arr, int n)
{
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(arr[i]);

    unordered_map<int, int> mp;
    int count = 1;
    for (int it : s)
    {
        mp[it] = count;
        count++;
    }

    for (int i = 1; i <= n; i++)
        arr[i] = mp[arr[i]];
}

int main()
{

    FWTree ft1;
    FWTree ft2;

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    coordinateCompression(arr, n);

    for (int i = 1; i <= n; i++)
        ft1.update(arr[i], 1);

    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        ft1.update(arr[i], -1);
        int c1 = ft1.sum(arr[i] - 1);
        int c2 = ft2.sum(1000001) - ft2.sum(arr[i]);
        ft2.update(arr[i], 1);

        count += c1 * c2;
    }

    cout << count << "\n";

    return 0;
}