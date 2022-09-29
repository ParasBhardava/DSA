#include<bits/stdc++.h>
using namespace std;

int difference(int arr[], int n)
{
    int sum = accumulate(arr, arr+n, 0);
    bool t[n+1][sum+1];

    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            if(i == 0)
                t[i][j] = false;

            else if(j == 0)
                t[i][j] = true;

            else if(arr[i-1] <= j)
                t[i][j] = (t[i-1][j-arr[i-1]] || t[i-1][j]);

            else
                t[i][j] = t[i-1][j];
        }
    }

    vector<int>v;
    for(int i=0; i<=sum/2; i++)
    {
        if(t[n][i] == true)
            v.push_back(i);
    }

    int mn = INT_MAX;
    for(int i=0; i<v.size(); i++)
    {
        mn = min(mn, sum-2*v[i]);
    }

    return mn;
}

int main()
{
    int n = 4;
    int arr[] = {1, 6, 11, 5};
    cout<<difference(arr, n)<<"\n";
    
    return 0;
}