#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>>&adjl, vector<bool>&visited)
{
    visited[node] = true;
    
    // For preorder
    cout<<node<<" ";

    for(auto it = adjl[node].begin(); it != adjl[node].end(); it++)
    {
        if(!visited[*it])
        {
            DFS(*it, adjl, visited);
        }
    }

    // For postorder
    // cout<<node<<" ";
}

int main()
{
    int n;      // no. of nodes
    int m;      // no. of adges
    cin>>n>>m;

    vector<vector<int>>adjl(n+1);
    vector<bool>visited(n+1, false);

    for(int i = 0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;

        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    
    
    for(int i = 1; i<n+1; i++)
    {
        if(!visited[i])
            DFS(i, adjl, visited);
    }
    
return 0;
}
