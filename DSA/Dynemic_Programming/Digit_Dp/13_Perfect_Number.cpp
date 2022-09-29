// Problem Link : https://codeforces.com/contest/919/problem/B

#include <bits/stdc++.h>
using namespace std;

bool solve(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum == 10;
}

int main()
{
    int k;
    cin >> k;

    int curr = 1;
    while (1)
    {

        if (solve(curr))
            k--;

        if (k == 0)
        {
            cout << curr << "\n";
            break;
        }

        curr++;
    }
    return 0;
}