// Problem Link : https://codeforces.com/problemset/problem/52/C

#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> seg;
    vector<int> lazy;

public:
    SegmentTree(int n)
    {
        int h = ceil(log2(n));
        int size = 2 * pow(2, h);
        seg.resize(size);
        lazy.resize(size);
    }

    void build(vector<int> &arr)
    {
    }
};

int main()
{
    int n = 4;
    vector<int> arr = {1, 2, 3, 4};

    return 0;
}