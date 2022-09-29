#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

// b <= 10 ^ 18

int binExp(int a, long long b, int M)
{
    int ans = 1;

    while (b)
    {
        if (b & 1) // if(b % 2 == 1)
        {
            ans = (ans * 1LL * a) % M;
        }

        a = (a * 1LL * a) % M;
        b >>= 1; // (b = b/2)
    }
    return ans;
}

int main()
{
    cout << binExp(59, binExp(64, 32, MOD - 1), MOD);
    return 0;
}

// suppose we want to calculate: 59^64^32
// a and b said coprime if they have only one factor which is 1, in other words gcd(a, b) = 1
// ex. 6 and 7
// number and itself in not coprime

// no of coprime of any n:
// n * multipy(1 - 1/p)
//     p = unique prime factors of n

// 5 : 5*(5 - 1/5) = 4 (1, 2, 3, 4)
// 6 : 6(6 - 1/2)(1 - 1/3) = 2 (1, 5)
// 12 : 12*(1 - 1/2)(1 - 1/3) = 4 (1, 5, 7, 11)

// Eular's Theorem :
// (a ^ b) = (a ^ (b mod(no of coprime of M))) mod(M)
// (a ^ b) % MOD = (a ^ (b % no of coprime of MOD)) % MOD     --->  if MOD is any number

// if MOD is prime then no of coprime of MOD is: (MOD - 1)
// (a ^ b) % MOD = (a ^ (b % (MOD - 1))) % MOD                ---> MOD is a prime number