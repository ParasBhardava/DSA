#include <bits/stdc++.h>
using namespace std;
const long long M = 1e18;

// a <= 10^18(2 ^ 1024)
// MOD <= 10 ^ 18
long long binMultiply(long long a, long long b)
{
    long long ans = 0;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans + a) % M;

        a = (a + a) % M;
        b >>= 1;
    }
    return ans;
}

long long binExp(long long a, long long b)
{
    long long ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = binMultiply(ans, a);

        a = binMultiply(a, a);
        b >>= 1;
    }
    return ans;
}

int main()
{
    cout << binExp(2, 10);
    return 0;
}

// Time Complexity : log^2(n)