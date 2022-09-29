#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int steps = (arr[i - 1] * arr[k] * arr[j]) + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
        mini = min(mini, steps);
    }

    return dp[i][j] = mini;
}

int main()
{
    int n = 5;
    vector<int> arr = {40, 20, 30, 10, 30};

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << solve(1, n - 1, arr, dp) << "\n";

    return 0;
}

// Recursion :
// Time complexity : Exponential
// Space compleity : O(N)  ---> (auxiliary stack space)

// Memoiztion :
// Time Complexity : O(N * N * N)
// space Complexity : O(N * N) for dp array + O(N) for auxiliary stack space

/*
  0   1   2   3   4
[40, 20, 30, 10, 30]
     A   B   C   D

suppose we have 4 matrix
A = first matrix  = arr[0] X arr[1] = 40 X 20
B = second matrix = arr[1] X arr[2] = 20 X 30
C = third matrix  = arr[2] X arr[3] = 30 X 10
D = fourth matrix = arr[3] X arr[4] = 10 X 30

Nth matrix = arr[n-1] X arr[n]

first first we take all partion 1 to (n-1)
then devide this partion from i to j - 1
and get minmum answer
*/