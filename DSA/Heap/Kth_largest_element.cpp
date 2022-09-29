#include<bits/stdc++.h>
using namespace std;

int KthLargestElement(vector<int>&v, int k)
{
    priority_queue<int, vector<int>, greater<int>>minHeap;

    for(int i = 0; i<v.size(); i++)
    {
        minHeap.push(v[i]);

        if(minHeap.size() > k)
            minHeap.pop();
    }

    return minHeap.top();
}

int main()
{
    vector<int>v{7, 10, 4, 3, 20, 15};
    int k = 3;

    cout<<KthLargestElement(v, k);
}