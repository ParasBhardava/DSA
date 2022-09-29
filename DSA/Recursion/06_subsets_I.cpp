#include<iostream>
#include<vector>
using namespace std;

void subsets(int idx, vector<int>&arr, vector<int>&ans, vector<vector<int>>&res)
{
    if(idx == arr.size())
    {
        res.push_back(ans);
        return;
    }

    // not pick current index 
    subsets(idx + 1, arr, ans, res);             
    
    // pick current index
    ans.push_back(arr[idx]);
    subsets(idx + 1, arr, ans, res);  
    ans.pop_back();
}

int main()
{
    vector<int>arr{1,2 ,3};
    vector<int>ans;
    vector<vector<int>>res;
    subsets(0, arr, ans, res);

    for(auto &a: res)
    {
        for(auto &i: a)
            cout<<i<<" ";
        cout<<"\n"; 
    }

    return 0;
}

// Note : Subsets, powersets and subsequence are all solve with this 