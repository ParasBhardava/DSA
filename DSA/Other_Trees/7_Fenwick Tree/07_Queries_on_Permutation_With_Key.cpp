#include <bits/stdc++.h>
using namespace std;

class FWTree
{
    int n;
    vector<int> fenweek;

public:
    FWTree(int size)
    {
        this->n = size;
        fenweek.resize(size + 1);
        fenweek[0] = 0;
    }

    void update(int idx, int val)
    {
        while (idx <= n)
        {
            fenweek[idx] += val;
            idx = idx + (idx & (-idx));
        }
    }

    int sum(int idx)
    {
        int s = 0;
        while (idx > 0)
        {
            s += fenweek[idx];
            idx = idx - (idx & -(idx));
        }

        return s;
    }
};

int main()
{
    int m = 5;
    vector<int> queries = {3, 1, 2, 1};

    int n = queries.size();
    FWTree ft(m + n);

    unordered_map<int, int> mp;
    for (int i = 1; i <= m; i++)
    {
        ft.update(n + i, 1);
        mp[i] = n + i - 1;
    }

    vector<int> ans;
    int curr = n - 1;
    for (int i = 0; i < n; i++)
    {
        int idx = mp[queries[i]];
        mp[queries[i]] = curr;

        ans.push_back(ft.sum(idx));
        ft.update(idx + 1, -1);
        ft.update(curr + 1, 1);

        curr--;
    }

    for (int it : ans)
        cout << it << " ";

    return 0;
}
