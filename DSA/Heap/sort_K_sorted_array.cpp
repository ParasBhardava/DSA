#include<bits/stdc++.h>
using namespace std;

vector<int> Sort(vector<int> &v, int k)
{
    priority_queue<int, vector<int>, greater<int>>minHeap;
    vector<int> ans;

    for(int i = 0; i<v.size(); i++)
    {
        minHeap.push(v[i]);
        if(minHeap.size() > k)
        {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
    }

    while(!minHeap.empty())
    {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }

    return ans;
}

int main()
{
    vector<int>v{6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    vector<int>sorted = Sort(v, k);

    for(auto i : sorted)
    cout<<i<<" ";

    return 0;
}

// sort a K sorted arry ---> sort a nearly sorted array