/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <bits/stdc++.h>
using namespace std;

int climbStairs(int idx, vector<int> &dp)
{
    if (idx == 0)
        return 1;

    if (idx == 1)
        return 1;

    if (dp[idx] != -1)
        return dp[idx];

    int first = climbStairs(idx - 1, dp);
    int second = climbStairs(idx - 2, dp);

    return dp[idx] = first + second;
}

int main()
{
    int n = 3;
    vector<int> dp(n + 1, -1);
    cout << climbStairs(n, dp);
    return 0;
}