// LDE : Linear Diophantine Equations
// ax + by = c eqation given
// (a, b, c)

// Find GCD of a and b
// Check if c % GCD(a ,b) == 0 then solution is possible otherwise solution is not posiible

#include <bits/stdc++.h>
using namespace std;

bool solve(int a, int b, int c)
{
    return (c % __gcd(a, b) == 0);
}

int main()
{
    int a = 3, b = 6, c = 8;
    cout << solve(a, b, c) << "\n";

    return 0;
}

// Problem Link:
//  https://codeforces.com/problemset/problem/633/A?f0a28=1