// Problem Link : https://www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practice-problems/algorithm/shinos-k-special-cells-c8538ebb/

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long fact[1000001], inv[1000001];

long long power(long long base, long long n, long long MOD)
{
    long long ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = (ans * base) % MOD;
            n = n - 1;
        }

        else
        {
            n = n >> 1;
            base = (base * base) % MOD;
        }
    }

    return ans;
}

void precomputeFactorial()
{
    fact[0] = 1;
    inv[0] = 1;
    long long ans = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        ans = (ans * i) % MOD;
        fact[i] = ans;
        inv[i] = power(fact[i], MOD - 2, MOD);
    }
}

int nCr(int n, int r)
{
    // n! / ((n - r)! * r!)
    long long ans = (fact[n] * (inv[r] * inv[n - r]) % MOD) % MOD;
    return ans;
}

int main()
{
    precomputeFactorial();
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        long long ans = 0;
        cin >> n >> m >> k;
        while (k--)
        {
            int x, y, s;
            cin >> x >> y >> s;

            int path1 = nCr(x + y - 2, x - 1);

            int p = (n - x + 1);
            int q = (m - y + 1);
            int path2 = nCr(p + q - 2, p - 1);
            ans = (ans + (s * (path1 * path2) % MOD)) % MOD;
        }
        cout << ans << "\n";
    }

    return 0;
}

// Input :
// 0 0 0
// 2 6 0
// 0 0 0

// 6
// 6
// 2 6
// 2 6
// 2

// ans :

// For 6
// path1 = from (0, 0) to (1, 1)
// (2 + 2 - 2)C(2 - 1) = 2C1 = 2
// ath2 = from (1, 1) to (2, 2)
// (2 + 2 - 2)C(2 - 1) = 2C1 = 2
// total contibution 0f 6 : path1 * path2 * 6 = 2 * 2 * 6 = 24

// For 2
// Path1 = from (0, 0) to (1, 0)
// (2 + 1 - 2)C(2 - 1) = 1C1 = 1
// path2 = from (1, 0) to (2, 2)
// (3 + 2 - 2)C(2 - 1) = 3C1 = 3
// total contribution of 3 : path1 * path2 * 2 = 3 * 1 * 2 = 6

// ans : 24 + 6 = 30
