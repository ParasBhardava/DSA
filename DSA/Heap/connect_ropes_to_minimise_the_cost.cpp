#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &v)
{
    priority_queue<int, vector<int>, greater<int>>minHeap;

    for(int i =0; i<v.size(); i++)
    {
        minHeap.push(v[i]);
    }

    int sum = 0;
    while(minHeap.size() >= 2)
    {
        int first = minHeap.top();
        minHeap.pop();
        int second  = minHeap.top();
        minHeap.pop();

        int cost = first + second;
        minHeap.push(cost);
        sum += cost;
    }

    return sum;

}

int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    cout<<solve(v)<<"\n";

    return 0;
}

