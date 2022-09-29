#include<iostream>
#include<queue>

using namespace std;

int main()
{

    // Priority Queue: minHeap 
    priority_queue<int>pq1;
    pq1.push(2);
    pq1.push(4);
    pq1.push(8);
    pq1.push(3);
    pq1.push(5);
    pq1.push(1);

    while(!pq1.empty())
    {
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
    cout<<"\n";



    // Priority Queue: maxHeap
    priority_queue<int, vector<int>, greater<int>>pq2;
    pq2.push(2);
    pq2.push(4);
    pq2.push(8);
    pq2.push(3);
    pq2.push(5);
    pq2.push(1);

    while(!pq2.empty())
    {
        cout<<pq2.top()<<" ";
        pq2.pop();
    }
    cout<<"\n";

    return 0;
}