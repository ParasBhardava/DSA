#include <bits/stdc++.h>
using namespace std;

class FWTree
{
    int n;

public:
    vector<vector<int>> fenweek;
    FWTree(int size)
    {
        n = size;
        for (int i = 0; i <= n; i++)
            fenweek.push_back(vector<int>(n + 1, 0));
    }

    void update(int fenNo, int idx, int val)
    {
        while (idx <= n)
        {
            fenweek[fenNo][idx] += val;
            idx = idx + (idx & ~(idx - 1));
        }
    }

    int sum(int fenNo, int idx)
    {
        int s = 0;
        while (idx > 0)
        {
            s += fenweek[fenNo][idx];
            idx = idx - (idx & ~(idx - 1));
        }

        return s;
    }
};

int main()
{
    int n;
    cin >> n;

    FBTree ft(n);

    // For update
    int x, y, val;
    cin >> x >> y >> val;
    x += 1;
    y += 1;
    ft.update(x, y, val);

    // For sum
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += 1;
    y1 += 1;
    x2 += 1;
    y2 += 1;

    int s = 0;
    for (int fenNo = x1; fenNo <= x2; fenNo++)
        s += ft.sum(fenNo, y2) - ft.sum(fenNo, y1 - 1);

    cout << s << "\n";

    return 0;
}

// Problem Link : https://www.spoj.com/problems/MATSUM/

// n = 4;
// FWTree fb(n);
// fb.update(1, 1, 1);

// int s = 0;
// for (int i = 1; i <= 4; i++)
// {
//     s += fb.sum(i, 4) - fb.sum(i, 0);
// }
// cout << s << "\n";

// s = 0;
// fb.update(3, 3, 12);
// for (int i = 3; i <= 3; i++)
// {
//     s += fb.sum(i, 3) - fb.sum(i, 2);
// }
// cout << s << "\n";

// s = 0;
// for (int i = 3; i <= 4; i++)
// {
//     s += fb.sum(i, 4) - fb.sum(i, 2);
// }
// cout << s << "\n";

// s = 0;
// for (int i = 1; i <= 3; i++)
// {
//     s += fb.sum(i, 3) - fb.sum(i, 0);
// }
// cout << s << "\n";
