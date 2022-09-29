// In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{

    int n = arr.size();
    int prev = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int fs = abs(arr[i] - arr[i - 1]) + prev;
        int ss = INT_MAX;
        if (i > 1)
            ss = abs(arr[i] - arr[i - 2]) + prev2;

        int curr = min(fs, ss);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main()
{
    vector<int> arr = {10, 20, 30, 10};
    cout << solve(arr);
    return 0;
}