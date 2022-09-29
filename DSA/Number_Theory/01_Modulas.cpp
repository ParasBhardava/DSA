#include <bits/stdc++.h>
using namespace std;

long long powMod(long long a, long long b, long long MOD) // a ^ b
{
    long long ans = 1;

    while (b)
    {
        if (b & 1) // if(b % 2 == 1)
        {
            b = b - 1;
            ans = ((ans % MOD) * (a % MOD)) % MOD;
        }

        else
        {
            a = ((a * MOD) * (a % MOD)) % MOD;
            b >>= 1; // (b = b/2)
        }
    }
    return ans;
}

long long inverse(long long a, long long MOD)
{
    return powMod(a, MOD - 2, MOD);
}

long long addMod(long long a, long long b, long long MOD)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

long long subMod(long long a, long long b, long long MOD)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

long long mulMod(long long a, long long b, long long MOD)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

long long divMod(long long a, long long b, long long MOD)
{
    return ((a % MOD) * (inverse(b, MOD) % MOD)) % MOD;
}

int main()
{
    const int MOD = (int)1e9 + 7;
    return 0;
}

/*
M = 10^9 + 7

(a + b)%M = ((a % M) + (b % M)) % M
(a * b)%M = ((a % M) * (b % M)) % M
(a - b)%M = ((a % M) - (b % M) + M ) % M
(a / b)%M = ((a % M) * (b^-1)% M ) % M = ((a % M) * pow(b, M - 2) % M) % M

M = 10^9 + 7
very close to rough range of integer and it is prime number
MMI -> multiplicative inverse

*/

/*

Fermat's little theorem

Fermat's little theorem states that if p is a prime number, then for any integer a,
the number a^p − a is an integer multiple of p.
In the notation of modular arithmetic, this is expressed as

(a^p - a)(mod p) = 0;
a^p = a(mod p)
For example, if a = 2 and p = 7, then
2^7 = 128, and
128 − 2
= 126
= 7 × 18
is an integer multiple of 7.

If a is not divisible by p, Fermat's little theorem is equivalent to the statement that a^(p − 1) − 1 is an integer multiple of p, or in symbols:

a^(p-1) = 1(mod p)
For example, if a = 2 and p = 7, then
2^6 = 64, and
64 − 1
= 63
= 7 × 9
is thus a multiple of 7.




for inverse of a
a^(p-2) = a^-1(mod p)


*/