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

    void build(int idx, int low, int high, int arr[])
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
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r)
    {
        // no overlap
        // [l, r] [low, high] or [low, high] [l, r]
        if (r < low || high < l)
            return INT_MIN;

        // complete overlap
        // [l, low, high, r]
        if (l <= low && high <= r)
            return seg[idx];

        // partially overlap
        // [l, low, r, high] or [low, l, high, r]
        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return max(left, right);
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
    int arr1[n1] = {1, 2, 0, 3, 4, 1, 2};
    SGTree sg1(n1);
    sg1.build(0, 0, n1 - 1, arr1);

        return 0;
}