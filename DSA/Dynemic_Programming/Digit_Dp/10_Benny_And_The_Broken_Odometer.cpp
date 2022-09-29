// Problem Link : https://www.hackerearth.com/problem/algorithm/benny-and-the-broken-odometer/

#include <bits/stdc++.h>
using namespace std;

int dp[10][2][2];

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

int solve(int idx, int flag, int count, vector<int> &num)
{
    if (idx == num.size())
    {
        if (count == 0)
            return 1;

        return 0;
    }

    if (dp[idx][flag][count] != -1)
        return dp[idx][flag][count];

    int limit = num[idx];
    if (flag == 1)
        limit = 9;

    int ans = 0;
    for (int digit = 0; digit <= limit; digit++)
    {
        if (flag == 1)
        {
            if (digit == 3)
                ans += solve(idx + 1, flag, 1, num);

            else
                ans += solve(idx + 1, flag, count, num);
        }

        else
        {
            if (digit < num[idx])
            {
                if (digit == 3)
                    ans += solve(idx + 1, 1, 1, num);

                else
                    ans += solve(idx + 1, 1, count, num);
            }

            else
            {
                if (digit == 3)
                    ans += solve(idx + 1, flag, 1, num);

                else
                    ans += solve(idx + 1, flag, count, num);
            }
        }
    }

    return dp[idx][flag][count] = ans;
}

int main()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));
    vector<int> num = convertToVec(n);
    cout << solve(0, 0, 0, num) - 1;

    return 0;
}
