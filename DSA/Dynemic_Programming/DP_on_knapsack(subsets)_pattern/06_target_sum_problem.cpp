#include<bits/stdc++.h>
using namespace std;

int count(int arr[], int n, int target)
{
    int sum = accumulate(arr, arr + n, 0);
    sum = (sum + target) / 2;

    int t[n + 1][sum + 1];

    for (int i = 0; i <= sum; i++)
        t[0][i] = 0;
        
    for (int i = 0; i <= n; i++)
        t[i][0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];

            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
}


int main()
{
    int n = 4;
    int arr[] = {1, 1, 2, 3};
    int target = 1;
    cout<<count(arr, n, target)<<"\n";

    return 0;
}