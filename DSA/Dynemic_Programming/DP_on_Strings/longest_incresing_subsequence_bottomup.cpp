#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &arr)
{
    int n = arr.size();
    int ans = 1;
    vector<int> dp(n, 1);
    vector<int> hash(n, 1);

    int lastIdx = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && 1 + dp[j] > dp[i])
            {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }

        if (dp[i] > ans)
        {
            ans = dp[i];
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

    // Without using hash array
    // int count = ans;
    // vector<int> temp;
    // for (int i = n - 1; i >= 0 && count; i--)
    // {
    //     if (count == dp[i] && (!temp.size() || arr[i] < temp[temp.size() - 1]))
    //     {
    //         temp.push_back(arr[i]);
    //         count--;
    //     }
    // }

    reverse(temp.begin(), temp.end());

    for (auto &it : temp)
        cout << it << " ";
    cout << "\n";

    return ans;
}

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << LIS(arr) << "\n";
    return 0;
}