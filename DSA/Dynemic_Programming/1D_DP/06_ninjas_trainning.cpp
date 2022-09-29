// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn? You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

#include <bits/stdc++.h>
using namespace std;

int solve(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
                maxi = max(maxi, arr[0][task]);
        }

        return maxi;
    }

    if (dp[day][last] != -1)
        return dp[day][last];

    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int points = arr[day][task] + solve(day - 1, task, arr, dp);
            maxi = max(maxi, points);
        }
    }

    return dp[day][last] = maxi;
}

int main()
{
    int n = 3;
    vector<vector<int>> arr = {{10, 40, 70},
                               {20, 50, 80},
                               {30, 60, 90}};

    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << solve(n - 1, 3, arr, dp);

    return 0;
}