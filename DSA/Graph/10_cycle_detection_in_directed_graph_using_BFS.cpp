// Kahn's algo

#include<bits/stdc++.h>
using namespace std;

bool cycleDetection(int n, vector<int> adjl[])
{
    queue<int>q;
    vector<int> indegree(n, 0);

    for(int i=0; i<n; i++)
    {
        for(auto j : adjl[i])
            indegree[j]++;
    }

    for(int i = 0; i<n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for(auto i : adjl[node])
        {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        } 
    }

    if(count == n)
        return false;
    
    else
        return true;

}


int main()
{
    int n;      // no. of nodes
    int m;      // no. of adges
    cin>>n>>m;

    vector<int> adjl[n];

    for(int i = 0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        adjl[x].push_back(y);
    }

    cout<<cycleDetection(n, adjl);

    return 0;
}
