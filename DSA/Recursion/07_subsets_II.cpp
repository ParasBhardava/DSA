#include <bits/stdc++.h>
using namespace std;

void subsets(int idx, vector<int> &arr, vector<int> &ans, vector<vector<int>> &res)
{
    res.push_back(ans);
    for (int i = idx; i < arr.size(); i++)
    {
        if (i != idx && arr[i] == arr[i - 1])
            continue;

        ans.push_back(arr[i]);
        subsets(i + 1, arr, ans, res);
        ans.pop_back();
    }
}

int main()
{
    vector<int> arr{2, 1, 2};
    vector<int> ans;
    vector<vector<int>> res;

    sort(arr.begin(), arr.end());
    subsets(0, arr, ans, res);

    for (auto &a : res)
    {
        for (auto &i : a)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}