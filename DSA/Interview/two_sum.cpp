#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5, target = 14;
    int arr[n] = {2, 6, 5, 8, 11};

    unordered_map<int, int>mp;
    for(int i = 0; i<n; i++)
    {
        if(mp.find(target - arr[i]) != mp.end())
        {
            cout<<mp[target-arr[i]]<<" ";
            cout<<i;
            break;
        }
                    
            mp[arr[i]] = i;
    }

}