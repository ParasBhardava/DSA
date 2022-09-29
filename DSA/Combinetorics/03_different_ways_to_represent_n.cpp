// Different ways to represenrt n as sum of k nonzero integers

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

    int n, k;
    cin >> n >> k;
    cout << nCr(n - 1, k - 1) << "\n";

    return 0;
}

/*
n = 5, k = 3

3 1 1
1 3 1
1 1 3
2 2 1
2 1 2
1 2 2

ans = 6


1_1_1_1_1 = 5
We want to put 2 comma in 4 spaces
we want to put k - 1 comma in n - 1 spaces
(n - 1)C(k -1) ways

*/