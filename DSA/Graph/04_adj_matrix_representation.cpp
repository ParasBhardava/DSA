#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;      // no. of nodes
    int m;      // no. of adges
    cin>>n>>m;

    int adjm[n+1][n+1];
    memset(adjm, 0, sizeof(adjm));

    for(int i = 0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }

    cout<<"Adjacency matrix of above graph is given by :\n";
    for(int i = 1; i<n+1; i++)
    {
        for(int j = 1; j<n+1; j++)
            cout<<adjm[i][j]<<" ";

        cout<<"\n";
    }

    return 0;
}

// space complexit :O(N*N)