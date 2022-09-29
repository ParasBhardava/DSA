#include <bits/stdc++.h>

using namespace std;

void printBinary(int num)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

int main()
{
    int a = 9;
    int b = 3;
    printBinary(a);

    // Check set bit
    a &(1 << b) ? cout << "set bit\n" : cout << "not set bit\n";

    // set bit
    printBinary(a | (1 << 1));

    // unset bit
    printBinary(a & (~(1 << 3)));

    // toggle bit
    printBinary(a ^ (1 << 2));

    // bit count, TC : O(32)
    int count = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((a & (a << i)) != 0)
            count++;
    }
    cout << count << "\n";

    // Another Method, TC : O(no. of setbits)
    // int count = 0;
    // while (n)
    // {
    //     count++;
    //     n = n & (n - 1);
    // }

    // Check for first set bit
    // int i = 0;
    // while (n)
    // {
    //     if (n & 1)
    //     {
    //         cout << i << " ";
    //         break;
    //     }
    //     n >>= 2;
    // }

    // CHeck for last set bit
    // cout << log2(n) << "\n";    // we can also check using loop of 32 bits

    cout << __builtin_popcount(a) << "\n";
    cout << __builtin_popcountll(1LL << 35) << "\n";
    cout << __builtin_popcountll((1LL << 35) - 1) << "\n";

    // unset the LSB till ith bit
    printBinary(59);
    int i = 4;
    printBinary(59 & (~((1 << (i + 1)) - 1)));

    // unset the MSB till ith bit
    printBinary(59);
    i = 3;
    printBinary(59 & ((1 << (i + 1)) - 1));

    // check if number is power of 2
    int n = 16;
    if (n & (n - 1))
        cout << n << " is not power of 2\n";
    else
        cout << n << " is power of 2\n";

    return 0;
}

/*

MSB          LSB
|             |
1 0 1 1 1 0 1 1
<--------------

*/