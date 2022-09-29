#include <bits/stdc++.h>
using namespace std;

void build(int idx, int low, int high, int arr[], int seg[])
{
    if (low == high)
    {
        seg[idx] = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid, arr, seg);
    build(2 * idx + 2, mid + 1, high, arr, seg);
    // cout << idx << " ";
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int query(int idx, int low, int high, int l, int r, int seg[])
{
    // no overlap
    // [l, r] [low, high] or [low, high] [l, r]
    if (r < low || high < l)
        return INT_MAX;

    // complete overlap
    // [l, low, high, r]
    if (low >= l && high <= r)
        return seg[idx];

    // partially overlap
    // [low, l, r, high]
    int mid = (low + high) / 2;
    int left = query(2 * idx + 1, low, mid, l, r, seg);
    int right = query(2 * idx + 2, mid + 1, high, l, r, seg);
    return min(left, right);
}

void update(int idx, int low, int high, int i, int val, int seg[])
{
    if (low == high)
    {
        seg[idx] = val;
        return;
    }

    int mid = (low + high) / 2;
    if (i <= mid)
        update(2 * idx + 1, low, mid, i, val, seg);

    else
        update(2 * idx + 2, mid + 1, high, i, val, seg);

    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int main()
{
    int n = 7;
    int arr[n] = {1, 2, 6, 3, 0, 7, 1};

    cout << __builtin_popcount(4);

    return 0;
}
