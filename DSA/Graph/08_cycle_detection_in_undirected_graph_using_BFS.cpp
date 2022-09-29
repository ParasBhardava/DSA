#include<bits/stdc++.h>
using namespace std;

bool checkForCycle(int start, int n, vector<int> adjl[], vector<bool>&visited)
{
    queue<pair<int, int>>q;
    visited[start] = true;
    q.push({start, -1});

    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto i: adjl[node])
        {
            if(!visited[i])
            {
                visited[i] =  true;
                q.push({i, node});
            }

            else if(i != parent)
                return true;
        }
    }

    return false;
}

bool isCycle(int n, vector<int> adjl[], vector<bool>&visited)
{
    for(int i = 1; i<n+1; i++)
    {
        if(!visited[i])
        {
            if(checkForCycle(i, n, adjl, visited))
                return true;
        }
    }

    return false;
}

int main()
{
    int n;      // no. of nodes
    int m;      // no. of adges
    cin>>n>>m;

    vector<int> adjl[n+1];
    vector<bool>visited(n+1, false);

    for(int i = 0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;

        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    cout<<isCycle(n, adjl, visited)<<"\n";

    return 0;
}

/*
       1---2             3---5---6---7
           |                 |       |
           4                10---9---8
                                      \
                                      11
*/
