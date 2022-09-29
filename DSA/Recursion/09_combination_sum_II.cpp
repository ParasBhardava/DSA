#include <bits/stdc++.h>
using namespace std;

void solve(int idx, int target, vector<int> &arr, vector<int> &ans, vector<vector<int>> &res)
{
    if (target == 0)
    {
        res.push_back(ans);
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        if (i > idx && arr[i] == arr[i - 1])
            continue;

        if (target - arr[i] < 0)
            break;

        ans.push_back(arr[i]);
        solve(i + 1, target - arr[i], arr, ans, res);
        ans.pop_back();
    }
}

int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<int> ans;
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());

    solve(0, target, arr, ans, res);

    for (auto &ans : res)
    {
        for (auto &i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}