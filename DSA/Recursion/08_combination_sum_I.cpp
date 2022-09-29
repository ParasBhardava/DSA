#include <bits/stdc++.h>
using namespace std;

void solve(int idx, int target, vector<int> &arr, vector<int> &ans, vector<vector<int>> &res)
{
    if (idx == arr.size())
    {
        if (target == 0)
            res.push_back(ans);

        return;
    }

    if (arr[idx] <= target)
    {
        ans.push_back(arr[idx]);
        solve(idx, target - arr[idx], arr, ans, res);
        ans.pop_back();
    }

    solve(idx + 1, target, arr, ans, res);
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;

    vector<int> ans;
    vector<vector<int>> res;

    solve(0, target, arr, ans, res);

    for (auto &ans : res)
    {
        for (auto &i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}