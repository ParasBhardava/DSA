#include<bits/stdc++.h>
using namespace std;

char nextAlpha(char arr[], int start, int end, char val)
{
    char ans = '#';

    while(start <= end)
    {
        int mid = end + ((start-end)/2);

        if(arr[mid] == val)
        {
            start = mid+1;
        }


        else if(arr[mid] < val)
        {
            start = mid+1;
        }

        else
        {
            ans = arr[mid];
            end = mid-1;
        }
    }

    return ans;
}

int main()
{
    char arr[] = {'a', 'c', 'f', 'h'};
    int start = 0, end = 3;
    char val = 'f';

    char ans = nextAlpha(arr, start, end, val);
    cout<<ans<<"\n";    
    return 0;
}