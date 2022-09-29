#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int>&visited, vector<int>&timeIn, vector<int>&low, int &timer, vector<int>adjl[], vector<int>&isArticulation)
{
    visited[node] = 1;
    timeIn[node] = low[node] = timer++;
    int child = 0;

    for(auto &i: adjl[node])
    {
        if(i == parent)
            continue;

        if(!visited[i])
        {
            dfs(i, node, visited, timeIn, low, timer, adjl, isArticulation);
            low[node] = min(low[node], low[i]);
            child++;

            if(low[i] >= timeIn[node] && parent != -1)
            isArticulation[node] = 1;
        }

        else
        {
            low[node] = min(low[node], timeIn[i]);
        }
    }

    if(parent == -1 && child > 1)
    {
        isArticulation[node] = 1;
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
    vector<int>isArticulation(n, 0);
    int timer = 0;

    for(int i = 0; i<n; i++)
    {
        if(!visited[i])
            dfs(i, -1, visited, timeIn, low, timer, adjl, isArticulation);
    }

    for(int i = 0; i < n; i++)
    {
        if(isArticulation[i] == 1)
            cout<<i<<" ";
    }

    return 0;
}


// low[adj] >= timeIn[node] && parent != -1
// then it is articulation point