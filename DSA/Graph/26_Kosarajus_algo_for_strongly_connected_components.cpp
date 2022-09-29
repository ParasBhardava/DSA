// reverse dfs(use topological sort)

/*
1. Sort all nodes in order b finishing time(find topological sort)
2. Transpose the Graph
3. DFS according to finishing time(according to topological sort)
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int>&st, vector<int>&visited, vector<int>adjl[])
{
    visited[node] = true;

    for(int i : adjl[node])
    {
        if(!visited[i])
            dfs(i, st, visited, adjl);
    }

    st.push(node);
}

void revDfs(int node, vector<int>&visited, vector<int>transpose[])
{
    cout<<node<<" ";
    visited[node] = true;

    for(auto i : transpose[node])
    {
        if(!visited[i])
            revDfs(i, visited,transpose);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int>adjl[n];
    for(int i = 0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adjl[u].push_back(v);
    } 

    stack<int>st;
    vector<int>visited(n, 0);
    for(int i = 0; i<n; i++)
    {
        if(!visited[i])
            dfs(i, st, visited, adjl);
    }

    vector<int>transpose[n];
    for(int u = 0; u<n; u++)
    {
        visited[u] = 0;
        for(auto v : adjl[u])
            transpose[v].push_back(u);
    }

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if(!visited[node])
        {
            cout<<"SCC : ";
            revDfs(node, visited, transpose);
            cout<<"\n";
        }
    }

    return 0;
}

// Time Complexity : O(N + E)
// Space Complexity : O(N+E) + O(N) + O(N)