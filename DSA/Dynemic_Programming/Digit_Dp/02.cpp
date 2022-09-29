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

int dp[19][2][172];

int solve(int idx, int flag, int sum, vector<int> &num)
{
    if (idx == num.size())
        return sum;

    if (dp[idx][flag][sum] != -1)
        return dp[idx][flag][sum];

    int limit = num[idx];

    if (flag == 1)
        limit = 9;

    int ans = 0;
    for (int digit = 0; digit <= limit; digit++)
    {
        if (flag == 1)
            ans += solve(idx + 1, flag, sum + digit, num);

        else if (flag == 0)
        {
            if (digit < num[idx])
                ans += solve(idx + 1, 1, sum + digit, num);
            else
                ans += solve(idx + 1, 0, sum + digit, num);
        }
    }

    return dp[idx][flag][sum] = ans;
}

int main()
{
    // fin the sum of digit that apper in range l and r(inclusive)
    // l= 1, r = 12
    // 1 2 3 4 5 6 7 8 9 10 11 12
    // 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 1 + 0 + 1 + 1 + 1 + 2 = 51
    int l, r;
    cin >> l >> r;

    memset(dp, -1, sizeof(dp));
    vector<int> num = convertToVec(r);
    int right = solve(0, 0, 0, num);

    memset(dp, -1, sizeof(dp));
    num = convertToVec(l - 1);
    int left = solve(0, 0, 0, num);

    cout << right - left << "\n";
    return 0;
}
