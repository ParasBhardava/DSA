#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 7;
    int arr[] = {2, 5, 1, 8, 2, 9, 1};
    int windowSize = 3;

    int i=0, j=0, sum = 0, mx = INT_MIN;

    while(j<n)
    {
        sum += arr[j];

        if(j-i+1 < windowSize)
        {
            j++;
        }

        else if(j-i+1 == windowSize)
        {
            mx = max(mx, sum);
            sum = sum - arr[i];
            i++;
            j++;
        }
    }

    cout<<mx<<"\n";

    return 0;
}