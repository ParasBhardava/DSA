#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// a <= 10^9, b <= 10^9, MOD <= 10^9
int binExp(int a, int b)
{
    if (b == 0)
        return 1;

    int res = binExp(a, b / 2);

    if (b & 1)
    {
        return (a * (res * 1LL * res) % MOD) % MOD;
    }

    else
        return (res * 1LL * res) % MOD;
}

int main()
{
    cout << binExp(2, 13) << "\n";
    return 0;
}

// inbuilt pow(a, b) function return double so it causes precision error and somtime it will not giv correct ans