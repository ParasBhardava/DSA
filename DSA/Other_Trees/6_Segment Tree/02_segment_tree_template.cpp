#include <bits/stdc++.h>
using namespace std;

class SGTree
{
    vector<int> seg;

public:
    SGTree(int n)
    {
        int h = ceil(log2(n));
        int size = 2 * (int)pow(2, h);
        seg.resize(size + 1);
    }

    void build(int idx, int low, int high, vector<int> arr)
    {
        // leaf nodes
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r)
    {
        // no overlap
        // [l, r] [low, high] or [low, high] [l, r]
        if (r < low || high < l)
            return INT_MAX;

        // complete overlap
        // [l, low, high, r]
        if (l <= low && high <= r)
            return seg[idx];

        // partially overlap
        // [l, low, r, high] or [low, l, high, r]
        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int idx, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val);

        else
            update(2 * idx + 2, mid + 1, high, i, val);

        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
};

int main()
{

    int n1 = 7;
    vector<int> arr1 = {1, 2, 0, 3, 4, 1, 2};
    SGTree sg1(n1);
    sg1.build(0, 0, n1 - 1, arr1);

    int n2 = 5;
    vector<int> arr2 = {4, 6, 8, 3, 7};
    SGTree sg2(n2);
    sg2.build(0, 0, n2 - 1, arr2);

    cout << sg1.query(0, 0, n1 - 1, 3, 4) << "\n";
    sg1.update(0, 0, n1 - 1, 3, 5);
    cout << sg1.query(0, 0, n1 - 1, 3, 4) << "\n";

    cout << sg2.query(0, 0, n2 - 1, 1, 3) << "\n";
    sg2.update(0, 0, n2 - 1, 2, 1);
    cout << sg2.query(0, 0, n2 - 1, 1, 3) << "\n";
    return 0;
}