#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>>&adjl, vector<bool>&visited)
{
    stack<int>st;
    st.push(node);

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if(!visited[node])
        {
            cout<<node<<" ";
            visited[node] = true;
        } 

        for(auto &i :adjl[node])
        {
            if(!visited[i])
                st.push(i);
        }

    }
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
