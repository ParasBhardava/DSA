#include<bits/stdc++.h>
using namespace std;
bool checkForCycle(int node, int parent, vector<int> adjl[], vector<bool>&visited)
{
    visited[node] = true;
    for(auto i: adjl[node])
    {
        if(!visited[i])
        {
            if(checkForCycle(i, node, adjl, visited))
                return true;
        }

        else if(i != parent)
            return true;
    }

    return false;
}


bool isCycle(int n, vector<int> adjl[])
{
    vector<bool>visited(n+1, false);
    for(int i = 1; i<n+1; i++)
    {
        if(!visited[i])
        {
            if(checkForCycle(i, -1, adjl, visited))
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

    for(int i = 0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;

        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    cout<<isCycle(n, adjl)<<"\n";

    return 0;
}

/*
         1---3            2---5
             |            /   \
             4           /     6
                        /     /
                        8----7
*/