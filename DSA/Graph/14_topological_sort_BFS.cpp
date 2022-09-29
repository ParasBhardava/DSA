// kahn's algorithm

#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<int> adjl[])
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

    vector<int>topo;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto i : adjl[node])
        {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        } 
    }

    return topo;
}

int main()
{
    int n;      // no. of nodes
    int m;      // no. of adges
    cin>>n>>m;

    vector<int> adjl[n];
    vector<int>indegree(n, 0);

    for(int i = 0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;

        adjl[x].push_back(y);
        indegree[y]++;
    }

    vector<int>topo = topoSort(n, adjl);
    for(auto i : topo)
        cout<<i<<" ";


    return 0;
}

/*

Directed and Acyclic  Graph

                 5--->0--->4
                 |         |
                 *         *
                 2--->3--->1

                 5 4 2 3 1 0
                 4 5 2 3 1 0

*/