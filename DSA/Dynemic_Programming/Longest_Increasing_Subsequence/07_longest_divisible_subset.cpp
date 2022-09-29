/*
 Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 1), hash(n);

    int maxi = 1;
    int lastIdx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] % arr[j] == 0 && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }

        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIdx = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIdx]);
    while (hash[lastIdx] != lastIdx)
    {
        lastIdx = hash[lastIdx];
        temp.push_back(arr[lastIdx]);
    }

    reverse(temp.begin(), temp.end());

    return temp;
}

int main()
{
    vector<int> arr = {1, 16, 7, 8, 4};

    vector<int> ans = solve(arr);
    for (auto &it : ans)
        cout << it << " ";

    return 0;
}