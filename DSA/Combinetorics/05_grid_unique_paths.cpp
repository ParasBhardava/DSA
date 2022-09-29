// Problem Link : https://leetcode.com/problems/unique-paths/

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

long long nCr(int n, int r)
{
    // n! / ((n - r)! * r!)
    long long ans = (fact[n] * ((inv[r] * inv[n - r]) % MOD)) % MOD;
    return ans;
}

int uniquePaths(int m, int n)
{

    // We want to find (n + m - 2)C(n - 1)
    // or (n + m - 2)C(m - 1)
    // n, m <= 100

    long long N = m + n - 2;
    long long R = min(m - 1, n - 1);
    long long res = 1;
    long long div = 1;

    for (int i = 1; i <= R; i++)
    {
        res *= (N - R + i);
        div *= i;
    }
    return res / div;
}

int main()
{
    precomputeFactorial();

    long long n, m;
    cin >> n >> m;
    cout << uniquePaths(n, m) << "\n";
    cout << nCr(n + m - 2, n - 1) << "\n";
    return 0;
}