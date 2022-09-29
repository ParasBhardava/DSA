// Problem Link : https://www.spoj.com/problems/NUMTSN/

#include <bits/stdc++.h>
using namespace std;

int dp[52][2][52][52][52];

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

int solve(int idx, int flag, int three, int six, int nine, vector<int> &num)
{
    if (idx == num.size())
    {
        if (three >= 1 && three == six && six == nine)
            return 1;

        return 0;
    }

    if (dp[idx][flag][three][six][nine] != -1)
        return dp[idx][flag][three][six][nine];

    int limit = num[idx];
    if (flag == 1)
        limit = 9;

    int count = 0;
    for (int digit = 0; digit <= limit; digit++)
    {
        if (flag == 1)
        {
            if (digit == 3)
                count += solve(idx + 1, flag, three + 1, six, nine, num);

            else if (digit == 6)
                count += solve(idx + 1, flag, three, six + 1, nine, num);

            else if (digit == 9)
                count += solve(idx + 1, flag, three, six, nine + 1, num);

            else
                count += solve(idx + 1, flag, three, six, nine, num);
        }

        else
        {
            if (digit < num[idx])
            {
                if (digit == 3)
                    count += solve(idx + 1, 1, three + 1, six, nine, num);

                else if (digit == 6)
                    count += solve(idx + 1, 1, three, six + 1, nine, num);

                else if (digit == 9)
                    count += solve(idx + 1, 1, three, six, nine + 1, num);

                else
                    count += solve(idx + 1, 1, three, six, nine, num);
            }

            else
            {
                if (digit == 3)
                    count += solve(idx + 1, flag, three + 1, six, nine, num);

                else if (digit == 6)
                    count += solve(idx + 1, flag, three, six + 1, nine, num);

                else if (digit == 9)
                    count += solve(idx + 1, flag, three, six, nine + 1, num);

                else
                    count += solve(idx + 1, flag, three, six, nine, num);
            }
        }
    }

    return dp[idx][flag][three][six][nine] = count;
}

int main()
{
    int a, b;
    cin >> a >> b;

    memset(dp, -1, sizeof(dp));
    vector<int> num = convertToVec(b);
    int right = solve(0, 0, 0, 0, 0, num);

    memset(dp, -1, sizeof(dp));
    num = convertToVec(a - 1);
    int left = solve(0, 0, 0, 0, 0, num);

    cout << right - left << "\n";

    return 0;
}