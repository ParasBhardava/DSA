#include <bits/stdc++.h>
using namespace std;

class FWTree
{
    int n = 100005;
    vector<int> fenweek;

public:
    FWTree()
    {
        fenweek.resize(100005);
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
    vector<int> arr(n + 1);

    FWTree ft;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        ft.update(arr[i], 1);
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        ft.update(arr[i], -1);
        count += ft.sum(arr[i] - 1);
    }

    cout << count << "\n";

    return 0;
}
