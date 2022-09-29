// https://codeforces.com/problemset/problem/339/D
// Xenia and Bit Operations

#include <bits/stdc++.h>
using namespace std;

class SGTree
{
    vector<int> seg;

public:
    SGTree(int n)
    {
        int h = ceil(log2(n));
        int size = 2 * (int)pow(2, h) - 1;
        seg.resize(size + 1);
    }

    void build(int idx, int low, int high, vector<int> arr, int orr)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr, !orr);
        build(2 * idx + 2, mid + 1, high, arr, !orr);

        if (orr)
            seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
        else
            seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
    }

    void update(int idx, int low, int high, int orr, int i, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, !orr, i, val);

        else
            update(2 * idx + 2, mid + 1, high, !orr, i, val);

        if (orr)
            seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];

        else
            seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
    }

    void print()
    {
        for (auto it : seg)
            cout << it << " ";
        cout << "\n";
    }

    int getAns()
    {
        return seg[0];
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    int ele = pow(2, n);

    SGTree sg(ele);

    vector<int> arr(ele);
    for (int i = 0; i < ele; i++)
        cin >> arr[i];

    if (n % 2 == 0)
        sg.build(0, 0, ele - 1, arr, 0);
    else
        sg.build(0, 0, ele - 1, arr, 1);

    while (q--)
    {
        int i, val;
        cin >> i >> val;
        i--;

        if (n % 2 == 0)
            sg.update(0, 0, ele - 1, 0, i, val);
        else
            sg.update(0, 0, ele - 1, 1, i, val);

        cout << sg.getAns() << "\n";
    }

    return 0;
}

// input :
// 2 4
// 1 6 3 5
// 1 4
// 3 4
// 1 2
// 1 2