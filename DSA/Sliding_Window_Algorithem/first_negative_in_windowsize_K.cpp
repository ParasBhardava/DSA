#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 8;
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int windowSize = 3;

    int i=0, j=0;

    list<int>l;
    vector<int>ans;

    while(j<n)
    {
        if(arr[j] < 0)
            l.push_back(arr[j]);

        if(j-i+1 < windowSize)
            j++;

        else if(j-i+1 == windowSize)
        {
            if(l.size() == 0)
                ans.push_back(0);
            
            else
                ans.push_back(l.front());

            if(arr[i] == l.front())
                l.pop_front();

            i++;
            j++;
        }

    }

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";

    return 0;
}