#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n == 0)
        return 0;

    n = n - 1;
    // because we want to find pow(base, n - 1);

    vector<vector<int>> base(2, vector<int>(2, 0));
    base[0][0] = 1;
    base[0][1] = 1;
    base[1][0] = 1;
    base[1][1] = 0;

    vector<vector<int>> ans(2, vector<int>(2, 0));
    ans[0][0] = 1;
    ans[0][1] = 0;
    ans[1][0] = 0;
    ans[1][1] = 1;

    while (n)
    {
        if (n % 2 == 0)
        {
            vector<vector<int>> temp(2, vector<int>(2, 0));
            temp[0][0] = base[0][0] * base[0][0] + base[0][1] * base[1][0];
            temp[0][1] = base[0][0] * base[0][1] + base[0][1] * base[1][1];
            temp[1][0] = base[1][0] * base[0][0] + base[1][1] * base[1][0];
            temp[1][1] = base[1][0] * base[0][1] + base[1][1] * base[1][1];
            base = temp;

            n /= 2;
        }

        else
        {
            vector<vector<int>> temp(2, vector<int>(2, 0));
            temp[0][0] = ans[0][0] * base[0][0] + ans[0][1] * base[1][0];
            temp[0][1] = ans[0][0] * base[0][1] + ans[0][1] * base[1][1];
            temp[1][0] = ans[1][0] * base[0][0] + ans[1][1] * base[1][0];
            temp[1][1] = ans[1][0] * base[0][1] + ans[1][1] * base[1][1];

            ans = temp;
            n -= 1;
        }
    }

    return ans[0][0];
}

int main()
{
    cout << fib(0) << "\n";

    return 0;
}

// fibonacchi sequence
// 0 1 1 2 3 5 8 ...........