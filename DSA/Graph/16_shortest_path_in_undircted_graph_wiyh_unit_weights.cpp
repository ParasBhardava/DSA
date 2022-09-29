// Using BFS and Greedy algo

#include<bits/stdc++.h>
using namespace std;

void shortestPath(int n, vector<int> adjl[], int start)
{
    queue<int>q;
    vector<int> distance(n, INT_MAX);

    distance[start] = 0;
    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto i : adjl[node])
        {
            if(distance[node] + 1 < distance[i])
            {
                distance[i] = distance[node]+1;
                q.push(i);
            }
        }
    }

    for(int i = 0; i<n; i++)
        cout<<distance[i]<<" ";

    cout<<"\n";
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> adjl[n+1];

    for(int i = 0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    } 
    int start = 0;

    shortestPath(n, adjl, start);

    return 0;
}

/*
                1-----2
              / |      \
             0  |       \    7
              \ |        \ /  \
               3---4---5---6----8

*/