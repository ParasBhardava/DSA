// compute the xor between 1 to N
// N <= 10^18;

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 4 == 0)
        cout << n << "\n";

    else if (n % 4 == 3)
        cout << "0\n";

    else if (n % 4 == 1)
        cout << "1\n";

    else if (n % 4 == 2)
        cout << n + 1 << "\n";

    return 0;
}

/*

N      xor
1      1
2      3
3      0
4      4
5      1
6      7
7      0
8      8
9      1
10     11
11     0
12     12


Observe the pattern

*/