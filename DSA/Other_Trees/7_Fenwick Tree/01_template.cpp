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
    int n = 4;
    vector<int> arr = {0, 1, 2, 1, 2};

    FWTree ft(n);
    for (int i = 1; i <= n; i++)
        ft.update(i, arr[i]);

    for (int i = 0; i <= n; i++)
        cout << ft.fenweek[i] << " ";

    return 0;
}
