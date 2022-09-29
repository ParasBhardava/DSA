// Problem Link : https://codeforces.com/problemset/problem/459/D

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int idx = 1;

    while (idx <= 14)
    {
        cout << idx << " ";
        idx += idx & (-idx);
    }

    return 0;
}