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

int dp[19][2][10][10];

int solve(int idx, int flag, int first, int last, vector<int> &num)
{
    if (idx == num.size())
    {
        if (first == last)
            return 1;
        else
            return 0;
    }

    if (dp[idx][flag][first][last] != -1)
        return dp[idx][flag][first][last];

    int limit = num[idx];

    if (flag == 1)
        limit = 9;

    int ans = 0;
    for (int digit = 0; digit <= limit; digit++)
    {
        if (flag == 1)
        {
            if (first == 0)
                ans += solve(idx + 1, flag, digit, digit, num);
            else
                ans += solve(idx + 1, flag, first, digit, num);
        }

        else if (flag == 0)
        {
            if (digit < num[idx])
            {
                if (first == 0)
                    ans += solve(idx + 1, 1, digit, digit, num);
                else
                    ans += solve(idx + 1, 1, first, digit, num);
            }
            else
            {
                if (first == 0)
                    ans += solve(idx + 1, 0, digit, digit, num);
                else
                    ans += solve(idx + 1, 0, first, digit, num);
            }
        }
    }

    return dp[idx][flag][first][last] = ans;
}

int main()
{
    // Find the number betwwen l and r (incluive) where first digit is equal to last digit
    // l = 8, r = 54
    // 8 9 11 22 33 44 ----> ans = 6
    int l, r;
    cin >> l >> r;

    memset(dp, -1, sizeof(dp));
    vector<int> num = convertToVec(r);
    int right = solve(0, 0, 0, 0, num);

    memset(dp, -1, sizeof(dp));
    num = convertToVec(l - 1);
    int left = solve(0, 0, 0, 0, num);

    cout << right - left << "\n";
    return 0;
}