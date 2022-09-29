#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<pair<int, int>> adjl[], vector<bool>&visited, stack<int>&st)
{
    visited[node] = true;
    for(auto i : adjl[node])
    {
        if(!visited[i.first])
            findTopoSort(i.first, adjl, visited, st);
    }

    st.push(node);
} 


void shortestPath(int n, vector<pair<int, int>> adjl[], int start)
{
    stack<int>st;
    vector<bool>visited(n, false);

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
            findTopoSort(i, adjl, visited, st);
    }

    vector<int>distance(n, INT_MAX);
    distance[start] = 0;
    
    while(!st.empty())
    {
        int node= st.top();
        st.pop();

        if(distance[node] != INT_MAX)
        {
            for(auto i: adjl[node])
            {
                if(distance[node] + i.second < distance[i.first])
                    distance[i.first] = distance[node] + i.second;
            }
        }
    }

    for(auto i : distance)
        i == INT_MAX ? cout << "INF " : cout<<i<<" ";

}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>>adjl[n];

    for(int i = 0; i<m; i++)
    {
        int x, y, wt;
        cin>>x>>y>>wt;
        adjl[x].push_back({y, wt});
    }
    int start = 0;

    shortestPath(n, adjl, start);
}