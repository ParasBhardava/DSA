#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 7;
    int arr[] = {4,1,1,1,2,3,5};
    int k =  5;

    int i=0, j=0, sum = 0, mx = 0;

    while(j<n)
    {
        sum += arr[j];

        if(sum < k)
        {
            j++;
        }

        else if(sum == k)
        {
            cout<<i << " "<<j<<"\n";
            mx = max(mx, j-i+1);
            j++;
        }

        else if(sum > k)
        {
            while(sum > k)
            {
                sum -= arr[i];
                i++;
            }
            j++;
        }


    }

    cout<<mx<<"\n";

    return 0;
}