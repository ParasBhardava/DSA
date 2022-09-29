#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    int n = arr.size();
    int prev2 = 0;
    int prev = arr[0];

    for (int i = 1; i < n; i++)
    {

        int take = arr[i];
        if (i > 1)
            take += prev2;

        int dontTake = prev;

        int curr = max(take, dontTake);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1};
    cout << solve(arr);

    return 0;
}