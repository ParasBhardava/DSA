#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return arr[0];

    if(n == 2)
        return max(arr[0], arr[1]);

    return max(arr[n-1] + solve(arr, n-2), arr[n-2] + solve(arr, n-2));
}

int main()
{
    int n = 5;
    int arr[] = {2, 7, 9, 3, 1};

    cout<<solve(arr, n)<<"\n";
    return 0;
}