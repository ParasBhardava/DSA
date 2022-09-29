#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;      // no. of nodes
    int m;      // no. of adges
    cin>>n>>m;

    vector<pair<int, int>> adjl[n+1];

    for(int i = 0; i<m; i++)
    {
        int x, y, wt;
        cin>>x>>y>>wt;

        adjl[x].push_back({y, wt});
        adjl[y].push_back({x, wt});
    }

    
return 0;
}

// space complexity : O(N + 2E + 2E)