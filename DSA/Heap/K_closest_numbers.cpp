// Given an unsorted array and two numbers x and k find k closest value to x. 
 
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &v, int k, int x)
{
    priority_queue<pair<int, int>>maxHeap;   // priority_queue({abs(x-v[i]), v[i]})

    for(int i = 0; i<v.size(); i++)
    {
        maxHeap.push({abs(x-v[i]), v[i]});
        
        if(maxHeap.size() > k)
            maxHeap.pop();
    }

    vector<int>ans;
    while(!maxHeap.empty())
    {
        ans.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return ans;
}

int main()
{
    vector<int> v{10, 2, 14, 4, 7, 6};
    int x = 5;
    int k = 3;

    vector<int>ans = solve(v, k, x);
    for(auto i: ans)
        cout<<i<<" ";

    return 0;
}