#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node, vector<int> adjl[], vector<bool>&visited, vector<bool>&dfsvisited)
{
    visited[node] = 1;
    dfsvisited[node] = 1;

    for(auto i: adjl[node])
    {
        if(!visited[i])
        {
            if(checkCycle(i, adjl, visited, dfsvisited))
                return true;
        }

        else if(dfsvisited[i])
            return true;
    }

    dfsvisited[node] = 0;
    return false;
}

bool cycleDetection(int n, vector<int> adjl[])
{
    vector<bool>visited(n+1, false);
    vector<bool>dfsVisited(n+1, false);

    for(int i = 0; i<n; i++)
    {
        if(!visited[i])
        {
            if(checkCycle(i, adjl, visited, dfsVisited))
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

    vector<int> adjl[n];

    for(int i = 0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        adjl[x].push_back(y);
    }

    cout<<cycleDetection(n, adjl);

    return 0;
}

/*
   

            
           
     1--->2-------->3--->4
          |  *      |    |
          *   \     *    *
          8--->9    6--->5


*/