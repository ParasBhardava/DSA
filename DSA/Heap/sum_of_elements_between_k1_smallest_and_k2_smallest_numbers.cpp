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
    vector<int> v{1, 3, 12, 5, 15, 11};        // all elements are distinct
    int k1 = 3;
    int k2 = 6;

    int l = KthSmallestElement(v, k1);
    int r = KthSmallestElement(v, k2);

    int sum = 0;
    for(int i = 0; i<v.size(); i++)
    {
        if(v[i] > l && v[i] < r)
            sum += v[i];
    }
    cout<<sum<<"\n";

    return 0;
}