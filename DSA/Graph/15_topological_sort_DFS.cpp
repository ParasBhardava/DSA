#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<int> adjl[], vector<bool>&visited, stack<int>&st)
{
    visited[node] = true;
    for(auto i : adjl[node])
    {
        if(!visited[i])
            findTopoSort(i, adjl, visited, st);
    }

    st.push(node);
} 

vector<int> topologicalSort(int n, vector<int> adjl[])
{
    stack<int>st;
    vector<bool>visited(n, false);

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
            findTopoSort(i, adjl, visited, st);
    }

    vector<int>topo;
    while(!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
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

    vector<int> topo = topologicalSort(n, adjl);
    for(auto i: topo)
        cout<<i<<" ";

    return 0;
}

// A topological ordering is an ordering of the nodes in a directed graph where for each directed edge from node A to B, node A appears before node B in the ordering

// NOTE : Topological ordering are not unique.
// Directed Cyclic Graph cannot have a Topological sort
// Only Directed Acyclic Graph(DAG) have a Topological sort


/*
                 5--->0--->4
                 |         |
                 *         *
                 2--->3--->1

                 5 4 2 3 1 0
                 4 5 2 3 1 0

*/