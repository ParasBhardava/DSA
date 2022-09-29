#include<bits/stdc++.h>
using namespace std;

int KthSmallestElement(vector<int>&v, int k)
{
    priority_queue<int>maxHeap;

    for(int i = 0; i<v.size(); i++)
    {
        maxHeap.push(v[i]);

        if(maxHeap.size() > k)
            maxHeap.pop();
    }

    return maxHeap.top();
}

int main()
{
    vector<int>v{7, 10, 4, 3, 20, 15};
    int k = 3;

    cout<<KthSmallestElement(v, k);
}