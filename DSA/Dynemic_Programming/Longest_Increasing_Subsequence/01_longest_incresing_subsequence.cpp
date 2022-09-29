#include <bits/stdc++.h>
using namespace std;

int LIS(int idx, vector<int> &arr, int prev)
{
    if (idx >= arr.size())
        return 0;

    int dontTake = LIS(idx + 1, arr, prev);
    int take = 0;

    if (arr[idx] > prev)
        take = 1 + LIS(idx + 1, arr, arr[idx]);

    return max(take, dontTake);
}

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << LIS(0, arr, INT_MIN);
    return 0;
}
