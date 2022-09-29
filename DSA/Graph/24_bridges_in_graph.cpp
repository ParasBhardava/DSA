#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int>&visited, vector<int>&timeIn, vector<int>&low, int & timer, vector<int>adjl[])
{
    visited[node] = true;
    timeIn[node] = low[node] = timer++;

    for(auto i : adjl[node])
    {
        if(i == parent)
            continue;

        if(!visited[i])
        {
            dfs(i, node, visited, timeIn, low, timer, adjl);
            low[node]= min(low[node], low[i]);

            if(low[i] > timeIn[node])
                cout<<node<<" "<<i<<endl;
            
        }
        
        else
            low[node] = min(low[node], timeIn[i]);
    
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adjl[n];

    for(int i =0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }

    vector<int>timeIn(n, -1);
    vector<int>low(n, -1);
    vector<int>visited(n, 0);
    int timer = 0;

    for(int i = 0; i<n; i++)
    {
        if(!visited[i])
            dfs(i, -1, visited, timeIn, low, timer, adjl);
    }

    return 0;
}


// low[adj] > timeIn[node]
// then it is bridge