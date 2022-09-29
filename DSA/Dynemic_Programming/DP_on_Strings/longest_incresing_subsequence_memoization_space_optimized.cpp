#include <bits/stdc++.h>
using namespace std;

int LIS(int idx, int prevIdx, vector<int> &arr, vector<int> &dp)
{
    cout << idx << " " << prevIdx << "\n";

    if (idx >= arr.size())
        return 0;
    if (dp[prevIdx + 1] != -1)
        return dp[prevIdx + 1];

    int dontTake = LIS(idx + 1, prevIdx, arr, dp);

    int take = 0;
    if (prevIdx == -1 || arr[idx] > arr[prevIdx])
        take = 1 + LIS(idx + 1, idx, arr, dp);

    return dp[prevIdx + 1] = max(take, dontTake);
}

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();
    vector<int> dp(n + 1, -1);

    cout << LIS(0, -1, arr, dp);
    cout << "\n";

    return 0;
}
