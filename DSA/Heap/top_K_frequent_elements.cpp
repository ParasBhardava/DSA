// Given an array of n numbers. Your task is to read numbers from the array and keep at-most K numbers at the top (According to their decreasing frequency) every time a new number is read. We basically need to print top k numbers sorted by frequency when input stream has included k distinct elements, else need to print all distinct elements sorted by frequency.

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>&v, int k)
{
    unordered_map<int, int>mp;

    for(int i = 0; i<v.size(); i++)
        mp[v[i]]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minHeap;    
    // priority_queue({requency of v[i], v[i]}) 
    
    for(auto i : mp)
    {
        minHeap.push({i.second, i.first});


        if(minHeap.size() > k)
            minHeap.pop();
    }

    vector<int>ans;
    while(!minHeap.empty())
    {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return ans;
}

int main()
{
    vector<int> v{1, 1, 1, 3, 2, 2, 4};
    int k = 2;

    vector<int>ans = solve(v, k);
    for(auto i: ans)
        cout<<i<<" ";

    return 0;
}