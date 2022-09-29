/*
Given the arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits.

Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00} 
       dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00} 
*/

#include<bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr+n);
    sort(dep, dep+n);

    int platformnNeeded = 1, result = 1;
    int i = 1, j = 0;

    while(i < n && j < n)
    {
        if(arr[i] <= dep[j])
        {
            platformnNeeded++;
            i++;
        }

        else if(arr[i] > dep[j])
        {
            platformnNeeded--;
            j++;
        }

        result = max(result, platformnNeeded);
    }

    return result;
}

int main()
{
    int n = 6;
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };

    cout<<findPlatform(arr, dep, n);
    return 0;
}