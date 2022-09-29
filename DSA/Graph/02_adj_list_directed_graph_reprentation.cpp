#include<bits/stdc++.h>
using namespace std;

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
    }

    
    cout<<"Adjacency list of above graph is given by :\n";
    for(int i = 1; i<n+1; i++)
    {
        cout<<i<<" -> ";
        for(int j = 0; j<adjl[i].size(); j++)
            cout<<adjl[i][j] << " ";

        cout<<"\n";
    }

return 0;
}

// space complexity : O(N+E)