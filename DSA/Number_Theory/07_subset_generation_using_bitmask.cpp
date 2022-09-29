#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> res;

    int subsetsCount = (1 << n);
    for (int mask = 0; mask < subsetsCount; mask++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                subset.push_back(arr[i]);
        }
        res.push_back(subset);
    }

    return res;
}

int main()
{
    int n = 3;
    vector<int> arr = {2, 4, 5};

    vector<vector<int>> res = subsets(arr);

    for (auto &it : res)
    {
        for (auto &it1 : it)
            cout << it1 << " ";

        cout << "\n";
    }

    return 0;
}