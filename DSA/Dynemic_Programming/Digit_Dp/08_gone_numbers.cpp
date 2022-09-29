#include <bits/stdc++.h>
using namespace std;

int dp[10][2][100];

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

int solve(int idx, int flag, int sum, unordered_set<int> &s, vector<int> &num)
{
    if (idx == num.size())
    {
        // cout << sum << " ";
        if (s.find(sum) == s.end())
            return 0;

        return 1;
    }

    if (dp[idx][flag][sum] != -1)
        return dp[idx][flag][sum];

    int limit = num[idx];
    if (flag == 1)
        limit = 9;

    int count = 0;
    for (int digit = 0; digit <= limit; digit++)
    {
        if (flag == 1)
            count += solve(idx + 1, flag, sum + digit, s, num);

        else
        {
            if (digit < num[idx])
                count += solve(idx + 1, 1, sum + digit, s, num);

            else
                count += solve(idx + 1, flag, sum + digit, s, num);
        }
    }

    return dp[idx][flag][sum] = count;
}

int main()
{
    unordered_set<int> s{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};

    int a, b;
    cin >> a >> b;

    memset(dp, -1, sizeof(dp));
    vector<int> num = convertToVec(b);
    int right = solve(0, 0, 0, s, num);

    memset(dp, -1, sizeof(dp));
    num = convertToVec(a - 1);
    int left = solve(0, 0, 0, s, num);

    cout << right - left << " ";

    return 0;
}