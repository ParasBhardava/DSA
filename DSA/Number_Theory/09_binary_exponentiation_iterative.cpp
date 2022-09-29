#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// a <= 10^9, b <= 10^9, MOD <= 10^9
int binExp(int a, int b)
{
    int ans = 1;

    while (b)
    {
        if (b & 1) // if(b % 2 == 1)
        {
            ans = (ans * 1LL * a) % MOD;
            b = b - 1;
        }

        else
        {
            a = (a * 1LL * a) % MOD;
            b >>= 1; // (b = b/2)
        }
    }
    return ans;
}

int main()
{
    cout << binExp(2, 4) << "\n";
    return 0;
}

// inbuilt pow(a, b) function return double so it causes precision error and somtime it will not giv correct ans