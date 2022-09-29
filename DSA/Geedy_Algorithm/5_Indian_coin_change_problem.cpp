#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>&arr, int amount)
{
    sort(arr.begin(), arr.end(), greater<int>());

    int count = 0;
    vector<int>ans;
    for(int i = 0; i < arr.size(); i++)
    {

        // ans += amount/arr[i];                     simple code for only count number of coins
        // amount -= (amount/arr[i]) * arr[i];

        while(amount >= arr[i])
        {
            amount -= arr[i];
            ans.push_back(arr[i]);
            count++;
        }
    }

    for(int i = 0; i < ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    
    return count;
}

int main()
{
    vector<int>arr{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int amount = 350;
    cout<<findMin(arr, amount)<<"\n";

    return 0;
}