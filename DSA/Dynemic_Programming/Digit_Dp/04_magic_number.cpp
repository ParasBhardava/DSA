// Problem Link : https://codeforces.com/problemset/problem/628/D

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int dp[2001][2][2000];
vector<int> convertToVec(string s)
{
    vector<int> num;
    for (char ch : s)
        num.push_back(ch - '0');

    return num;
}

int solve(int idx, int flag, int sum, int m, int d, vector<int> &num)
{
    if (idx == num.size())
    {
        if (sum == 0)
            return 1;
        return 0;
    }

    if (dp[idx][flag][sum] != -1)
        return dp[idx][flag][sum];

    int count = 0;
    if (idx % 2)
    {
        if (flag == 1)
        {
            count += solve(idx + 1, flag, (sum * 10 + d) % m, m, d, num);
        }

        else if (flag == 0 && d <= num[idx])
        {
            if (d < num[idx])
                count += solve(idx + 1, 1, (sum * 10 + d) % m, m, d, num);

            else
                count += solve(idx + 1, flag, (sum * 10 + d) % m, m, d, num);
        }
    }

    else
    {
        int limit = num[idx];
        if (flag == 1)
            limit = 9;

        for (int digit = 0; digit <= limit; digit++)
        {
            if (digit == d)
                continue;

            if (flag == 1)
                count += solve(idx + 1, flag, (sum * 10 + digit) % m, m, d, num);

            else
            {
                if (digit < num[idx])
                    count += solve(idx + 1, 1, (sum * 10 + digit) % m, m, d, num);

                else
                    count += solve(idx + 1, flag, (sum * 10 + digit) % m, m, d, num);
            }
        }
    }

    return dp[idx][flag][sum] = count;
}

bool bruteCheck(int m, int d, vector<int> &num)
{
    int sum = 0;
    int n = num.size();
    for (int i = 0; i < n; i++)
    {
        sum = (sum * 10 + num[i]) % m;

        if (i % 2 && num[i] != d)
            return false;

        else if (i % 2 == 0 && num[i] == d)
            return false;
    }

    if (sum == 0)
        return true;

    return false;
}

int main()
{

    // m = 2, d = 6
    // l = 10, r = 99
    // 16, 26, 36, 46, 56, 76, 86, 96 are d-magic numbers --->  ans = 8
    int m, d;
    string l, r;
    cin >> m >> d >> l >> r;

    memset(dp, -1, sizeof(dp));
    vector<int> num = convertToVec(r);
    int right = solve(0, 0, 0, m, d, num);

    memset(dp, -1, sizeof(dp));
    num = convertToVec(l);
    int left = solve(0, 0, 0, m, d, num);

    cout << right - left + bruteCheck(m, d, num);

    return 0;
}
