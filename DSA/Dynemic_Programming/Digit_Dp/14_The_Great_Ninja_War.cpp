// Problem Link : https://www.hackerearth.com/problem/algorithm/sallu-bhai-and-ias-8838ac8d/

#include <bits/stdc++.h>
using namespace std;

int dp[14][2][1000][520];

vector<int> convertToVec(int n)
{
    vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }

    reverse(num.begin(), num.end());
    return num;
}

int solve(int idx, int flag, int sum, int mask, vector<int> &num)
{
    if (idx == num.size())
    {
        cout << sum << " ";
        for (int i = 1; i <= 9; i++)
        {
            if (mask & (1 << i))
            {
                if (sum % i != 0)
                    return 0;
            }
        }

        return 1;
    }

    if (dp[idx][flag][sum][mask] != -1)
        return dp[idx][flag][sum][mask];

    int limit = num[idx];
    if (flag == 1)
        limit = 9;

    int count = 0;
    for (int digit = 0; digit <= 9; digit++)
    {
        int newMask = mask | (1 << digit);
        if (flag == 1)
            count += solve(idx + 1, flag, sum + (digit * digit), newMask, num);

        else
        {
            if (digit < num[idx])
                count += solve(idx + 1, 1, sum + (digit * digit), newMask, num);

            else
                count += solve(idx + 1, flag, sum + (digit * digit), newMask, num);
        }
    }

    return dp[idx][flag][sum][mask] = count;
}

int main()
{
    int l, r;
    cin >> l >> r;

    memset(dp, -1, sizeof(dp));
    vector<int> num = convertToVec(r);
    int right = solve(0, 0, 0, 0, num);

    // memset(dp, -1, sizeof(dp));
    // num = convertToVec(l - 1);
    // int left = solve(0, 0, 0, 0, num);

    // cout << right - left << " ";

    return 0;
}