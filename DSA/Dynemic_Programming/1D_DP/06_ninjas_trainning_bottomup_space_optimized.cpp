// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn? You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>> &arr)
{
    vector<int> prev(4, 0);

    prev[0] = max(arr[0][1], arr[0][2]);
    prev[1] = max(arr[0][0], arr[0][2]);
    prev[2] = max(arr[0][0], arr[0][1]);
    prev[3] = max(arr[0][1], max(arr[0][2], arr[0][0]));

    for (int day = 1; day < n; day++)
    {
        vector<int> curr(4, 0);
        for (int last = 0; last < 4; last++)
        {
            curr[last] = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int points = arr[day][task] + prev[task];
                    curr[last] = max(curr[last], points);
                }
            }
        }

        prev = curr;
    }

    return prev[3];
}

int main()
{
    int n = 3;
    vector<vector<int>> arr = {{10, 40, 70},
                               {20, 50, 80},
                               {30, 60, 90}};

    cout << solve(n, arr);

    return 0;
}