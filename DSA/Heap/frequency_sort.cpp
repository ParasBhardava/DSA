#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>&v)
{
    unordered_map<int, int>mp;

    for(int i = 0; i<v.size(); i++)
        mp[v[i]]++;

    priority_queue<pair<int, int> > maxHeap;    
    // priority_queue({frequency of v[i], v[i]}) 
    
    for(auto i : mp)
    {
        maxHeap.push({i.second, i.first});
    }

    vector<int>ans;
    while(!maxHeap.empty())
    {
        int freq = maxHeap.top().first;
        for(int i = 0; i<freq; i++)
            ans.push_back(maxHeap.top().second);

        maxHeap.pop();
    }

    return ans;
}

int main()
{
    vector<int> v{1, 1, 1, 3, 2, 2, 4};

    vector<int>ans = solve(v);
    for(auto i: ans)
        cout<<i<<" ";

    return 0;
}