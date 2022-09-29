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
    int arr[n] = {1, 2, 0, 3, 4, 1, 2};

    int seg[4 * n] = {0};
    build(0, 0, n - 1, arr, seg);

    // queries for finding min in range l to r
    cout << query(0, 0, n - 1, 0, 1, seg) << "\n";
    cout << query(0, 0, n - 1, 3, 4, seg) << "\n";
    cout << query(0, 0, n - 1, 1, 6, seg) << "\n";

    // update val at index i
    update(0, 0, n - 1, 2, 5, seg);

    // {1, 2, 5, 3, 4, 1, 2}
    cout << query(0, 0, n - 1, 0, 1, seg) << "\n";
    cout << query(0, 0, n - 1, 3, 4, seg) << "\n";
    cout << query(0, 0, n - 1, 1, 6, seg) << "\n";

    return 0;
}