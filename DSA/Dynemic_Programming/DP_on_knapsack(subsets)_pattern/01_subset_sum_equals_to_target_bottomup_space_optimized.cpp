// You are given an array/list ‘arr’ of ‘N’ positive integers and an integer ‘k’. Your task is to check if there exists a subset in ‘arr’ with a sum equal to ‘k’. Note: Return true if there exists a subset with sum equal to ‘k’. Otherwise, return false.

#include <bits/stdc++.h>
using namespace std;

bool solve(int target, vector<int> &arr)
{
    int n = arr.size();
    vector<int> prev(target + 1, false);

    prev[0] = true;

    if (arr[0] <= target)
        prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(target + 1, false);
        curr[0] = true;

        for (int j = 1; j <= target; j++)
        {
            bool take = false;
            if (j >= arr[i])
                take = prev[j - arr[i]];

            bool dontTake = prev[j];

            curr[j] = take | dontTake;
        }

        prev = curr;
    }

    return prev[target];
}

int main()
{
    int k = 4;
    vector<int> arr = {2, 5, 1, 6, 7};
    int n = arr.size();

    cout << solve(k, arr);

    return 0;
}