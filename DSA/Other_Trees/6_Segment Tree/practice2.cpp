// https://codeforces.com/problemset/problem/380/C
// C. Sereja and Brackets

#include <bits/stdc++.h>
using namespace std;

struct info
{
    int open;
    int close;
    int full;

    info(int _open = 0, int _close = 0, int _full = 0)
    {
        this->open = _open;
        this->close = _close;
        this->full = _full;
    }
};

info merge(info left, info right)
{
    info ans = info(0, 0, 0);
    ans.full = left.full + right.full + min(left.open, right.close);
    ans.open = left.open + right.open - min(left.open, right.close);
    ans.close = left.close + right.close - min(left.open, right.close);

    return ans;
}

void build(int idx, int low, int high, string &s, info seg[])
{
    if (low == high)
    {
        seg[idx] = info(s[low] == '(', s[low] == ')', 0);
        return;
    }

    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid, s, seg);
    build(2 * idx + 2, mid + 1, high, s, seg);

    seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
}

info query(int idx, int low, int high, int l, int r, info seg[])
{
    if (r < low || high < l)
        return info();

    if (low >= l && high <= r)
        return seg[idx];

    int mid = (low + high) / 2;
    info left = query(2 * idx + 1, low, mid, l, r, seg);
    info right = query(2 * idx + 2, mid + 1, high, l, r, seg);

    return merge(left, right);
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    info seg[4 * n];
    build(0, 0, n - 1, s, seg);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        info ans = query(0, 0, n - 1, l, r, seg);
        cout << ans.full * 2 << "\n";
    }

    return 0;
}

// input:
// ())(())(())(
// 7
// 1 1
// 2 3
// 1 2
// 1 12
// 8 12
// 5 11
// 2 10
