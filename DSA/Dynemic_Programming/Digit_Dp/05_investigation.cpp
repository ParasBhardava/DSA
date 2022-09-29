// Problem Link : https://lightoj.com/problem/investigation

#include <bits/stdc++.h>
using namespace std;

int dp[11][2][91][91];

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

int solve(int idx, int flag, int digitSum, int sum, int k, vector<int> &num)
{
    if (idx == num.size())
    {
        if (sum == 0 && digitSum % k == 0)
            return 1;
        return 0;
    }

    if (dp[idx][flag][digitSum][sum] != -1)
        return dp[idx][flag][digitSum][sum];

    int limit = num[idx];
    if (flag == 1)
        limit = 9;

    int count = 0;

    for (int digit = 0; digit <= limit; digit++)
    {
        if (flag == 1)
            count += solve(idx + 1, flag, digitSum + digit, (sum * 10 + digit) % k, k, num);

        else
        {
            if (digit < num[idx])
                count += solve(idx + 1, 1, digitSum + digit, (sum * 10 + digit) % k, k, num);

            else
                count += solve(idx + 1, flag, digitSum + digit, (sum * 10 + digit) % k, k, num);
        }
    }

    return dp[idx][flag][digitSum][sum] = count;
}

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

    if (k <= 90)
    {
        memset(dp, -1, sizeof(dp));
        vector<int> num = convertToVec(b);
        int right = solve(0, 0, 0, 0, k, num);

        memset(dp, -1, sizeof(dp));
        num = convertToVec(a - 1);
        int left = solve(0, 0, 0, 0, k, num);

        cout << right - left << "\n";
    }

    else
        cout << 0 << "\n";

    return 0;
}