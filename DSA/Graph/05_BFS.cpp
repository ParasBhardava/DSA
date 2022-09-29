#include<bits/stdc++.h>
using namespace std;

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

    queue<int>q;
    int start = 1;

    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        for(auto it = adjl[node].begin(); it != adjl[node].end(); it++)     
        {
            if(!visited[*it])
            {
                q.push(*it);
                visited[*it] = true;
            }
        }
    }

return 0;
}

// 7 7
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 2 7
// 3 7
