// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night. Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

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
    vector<int> arr = {2, 3, 2};

    int n = arr.size();
    vector<int> temp1, temp2;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(arr[i]);

        if (i != n - 1)
            temp2.push_back(arr[i]);
    }

    // if n == 1 (array contains only one element then ans is arr[0])
    cout << max(solve(temp1), solve(temp2));

    return 0;
}

/*

solve using prev qs.
n = 5

int ans1 = dont take last element
_ _ _ _ _ x

int ans2 = dont take first element
x _ _ _ _ _

ans = max(ans1, ans2)

*/