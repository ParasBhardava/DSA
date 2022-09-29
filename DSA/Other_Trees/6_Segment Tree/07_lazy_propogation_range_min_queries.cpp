#include <bits/stdc++.h>
using namespace std;

class ST
{
    vector<int> seg;
    vector<int> lazy;

public:
    ST(int n)
    {
        int h = (int)ceil(log2(n));
        int size = 2 * (int)pow(2, h) - 1;

        seg.resize(size + 1);
        lazy.resize(size + 1);
    }

    void build(int idx, int low, int high, int arr[])
    {
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

    void update(int idx, int low, int high, int l, int r, int val)
    {
        // first update previous remaining elements
        // and propogate downwards

        if (lazy[idx] != 0)
        {
            seg[idx] += lazy[idx];
            // propogate the lazy update downwards
            // for the remaining nodes to get update
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }

            lazy[idx] = 0;
        }

        // no overlap
        // don't do anything and return
        // [low, high][l, r] or  [l, r][low, high]
        if (high < l || r < low)
            return;

        // complete overlap
        // [l, low, high, h]
        if (low >= l && high <= r)
        {
            seg[idx] += val;
            // if not a leaf node, have childean
            if (low != high)
            {
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
            }

            return;
        }

        // partially overlap
        int mid = (low + high) / 2;
        update(2 * idx + 1, low, mid, l, r, val);
        update(2 * idx + 2, mid + 1, high, l, r, val);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r)
    {

        // upadte if any updates are remaining
        // as the node will stay fresh and updated
        if (lazy[idx] != 0)
        {
            seg[idx] += lazy[idx];
            // propogate the lazy update downwards
            // for the remaining nodes to get update
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }

            lazy[idx] = 0;
        }

        // no overlap
        if (high < l || r < low)
            return INT_MAX;

        // complete overlap
        if (low >= l && high <= r)
            return seg[idx];

        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);

        return min(left, right);
    }
};

int main()
{
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};

    ST st(n);
    st.build(0, 0, n - 1, arr);

    cout << st.query(0, 0, n - 1, 0, 4) << "\n";
    st.update(0, 0, n - 1, 1, 3, 2); // [1, 4, 5, 6, 5]
    cout << st.query(0, 0, n - 1, 0, 4) << "\n";
    cout << st.query(0, 0, n - 1, 1, 2) << "\n";

    return 0;
}