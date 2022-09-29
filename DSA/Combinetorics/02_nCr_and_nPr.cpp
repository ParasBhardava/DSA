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
            ans = ((ans * base) % MOD);
            n = n - 1;
        }

        else
        {
            n = n >> 1;
            base = ((base * base) % MOD);
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
        ans = ((ans * i) % MOD);
        fact[i] = ans;
        inv[i] = power(fact[i], MOD - 2, MOD);
    }
}

long long nCr(int n, int r)
{
    // n! / ((n - r)! * r!)
    long long ans = ((fact[n] * ((inv[r] * inv[n - r]) % MOD)) % MOD);
    return ans % MOD;
}

long long nPr(int n, int r)
{
    long long ans = ((fact[n] * inv[n - r]) % MOD);
    return ans;
}

int main()
{
    precomputeFactorial();

    int t;
    cin >> t;
    while (t--)
    {
        long long n, r;
        cin >> n >> r;
        cout << nCr(n, r) << "\n";
    }

    return 0;
}