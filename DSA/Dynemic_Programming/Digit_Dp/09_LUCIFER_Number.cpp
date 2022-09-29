// Problem Link: https://www.spoj.com/problems/LUCIFER/

#include <bits/stdc++.h>
using namespace std;

int dp[11][2][46][46];

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

unordered_set<int> s{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};

int check(int oddSum, int evenSum, int size)
{
    if (size % 2 == 1)
        swap(oddSum, evenSum);

    return s.count(evenSum - oddSum);
}
int solve(int idx, int flag, int oddSum, int evenSum, vector<int> &num)
{
    if (idx == num.size())
    {
        return check(oddSum, evenSum, num.size());
    }

    if (dp[idx][flag][oddSum][evenSum] != -1)
        return dp[idx][flag][oddSum][evenSum];

    int limit = num[idx];
    if (flag == 1)
        limit = 9;

    int count = 0;

    for (int digit = 0; digit <= limit; digit++)
    {

        if (flag == 1)
        {
            if (idx % 2 == 1)
                count += solve(idx + 1, flag, oddSum + digit, evenSum, num);

            else
                count += solve(idx + 1, flag, oddSum, evenSum + digit, num);
        }

        else
        {
            if (idx % 2 == 1)
            {
                if (digit < num[idx])
                    count += solve(idx + 1, 1, oddSum + digit, evenSum, num);

                else
                    count += solve(idx + 1, flag, oddSum + digit, evenSum, num);
            }

            else
            {
                if (digit < num[idx])
                    count += solve(idx + 1, 1, oddSum, evenSum + digit, num);

                else
                    count += solve(idx + 1, flag, oddSum, evenSum + digit, num);
            }
        }
    }

    return dp[idx][flag][oddSum][evenSum] = count;
}

int main()
{
    int l, r;
    cin >> l >> r;

    memset(dp, -1, sizeof(dp));
    vector<int> num = convertToVec(r);
    int right = solve(0, 0, 0, 0, num);

    int left = 0;
    if (l - 1 >= 0)
    {
        memset(dp, -1, sizeof(dp));
        num = convertToVec(l - 1);
        left = solve(0, 0, 0, 0, num);
    }

    // cout << right << " " << left << " ";
    cout << right - left << " ";

    return 0;
}
