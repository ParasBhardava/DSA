#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &arr)
{
    vector<int> temp;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (temp.size() == 0 || temp.back() < arr[i])
            temp.push_back(arr[i]);

        else
        {
            int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[idx] = arr[i];
        }
    }

    return temp.size();
}

int main()
{
    vector<int> arr{1, 2, 3, 2};
    // vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << LIS(arr) << "\n";

    return 0;
}