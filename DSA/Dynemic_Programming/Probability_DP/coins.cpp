/*
Let N be a positive odd number.
There are N coins, numbered 1,2,…,N. For each i (1≤i≤N), when Coin i is tossed, it comes up heads with probability p and tails with probability 1−p
Taro has tossed all the N coins. Find the probability of having more heads than tails.

N is an odd number.
1≤N≤2999
pi ​is a real number and has two decimal places.
0 < pi < 1

Link : https://atcoder.jp/contests/dp/tasks/dp_i
*/

#include <bits/stdc++.h>
using namespace std;

double solve(int idx, int Hcount, int n, vector<double> &arr, vector<vector<double>> &dp)
{

    if (idx == n)
    {
        if (Hcount > (n - Hcount))
            return 1.0;
        else
            return 0.0;
    }

    if (dp[idx][Hcount] != -1)
        return dp[idx][Hcount];

    return dp[idx][Hcount] = arr[idx] * solve(idx + 1, Hcount + 1, n, arr, dp) +
                             (1 - arr[idx]) * solve(idx + 1, Hcount, n, arr, dp);
}

int main()
{
    int n = 3;
    vector<double> arr = {0.30, 0.60, 0.80};

    vector<vector<double>> dp(n, vector<double>(n, -1));
    cout << solve(0, 0, n, arr, dp) << "\n";
    return 0;
}