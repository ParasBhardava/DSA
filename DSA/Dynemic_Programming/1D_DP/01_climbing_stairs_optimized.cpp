#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    if (n == 1 || n == 2)
        return n;

    int first = 1;
    int second = 2;
    int current;

    for (int i = 3; i <= n; i++)
    {
        current = first + second;
        first = second;
        second = current;
    }

    return current;
}

int main()
{
    int n = 3;
    cout << climbStairs(n);
    return 0;
}