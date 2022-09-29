#include <bits/stdc++.h>
using namespace std;

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

int dp[19][2][19];

int solve(int idx, int flag, int count, int d, int k, vector<int> &num)
{
    if (idx == num.size())
    {
        if (count == k)
            return 1;

        else
            return 0;
    }

    if (dp[idx][flag][count] != -1)
        return dp[idx][flag][count];

    int limit = num[idx];

    // If flag is 1 means the number is smaller hence the liberty
    // to fill up now increse from 0 to 9
    if (flag == 1)
        limit = 9;

    int ans = 0;
    for (int digit = 0; digit <= limit; digit++)
    {
        if (flag == 1)
        {
            if (digit == d)
                ans += solve(idx + 1, flag, count + 1, d, k, num);
            else
                ans += solve(idx + 1, flag, count, d, k, num);
        }

        else if (flag == 0)
        {
            if (digit == d)
            {
                if (digit < num[idx])
                    ans += solve(idx + 1, 1, count + 1, d, k, num);
                else
                    ans += solve(idx + 1, 0, count + 1, d, k, num);
            }

            else
            {
                if (digit < num[idx])
                    ans += solve(idx + 1, 1, count, d, k, num);
                else
                    ans += solve(idx + 1, 0, count, d, k, num);
            }
        }
    }

    return dp[idx][flag][count] = ans;
}

int main()
{
    // Find the number between l and r (inclusive) where digit d appers k no. of times
    // l = 16, r = 21, d = 2, k = 1;
    // 16 17 18 19 20 21 22 23
    // 20 21 23 (2 appers 1 time in each number) ----> ans = 3
    int l, r, d, k;
    cin >> l >> r >> d >> k;

    memset(dp, -1, sizeof(dp));
    vector<int> num = convertToVec(r);
    int right = solve(0, 0, 0, d, k, num);

    memset(dp, -1, sizeof(dp));
    num = convertToVec(l - 1);
    int left = solve(0, 0, 0, d, k, num);

    cout << right - left << "\n";
    return 0;
}