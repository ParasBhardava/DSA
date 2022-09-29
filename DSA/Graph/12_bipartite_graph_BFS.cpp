#include<bits/stdc++.h>
using namespace std;

bool bipartiteBFS(int start, vector<int> adjl[], int colour[])
{
    queue<int>q;
    q.push(start);
    colour[start] = 1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto i : adjl[node])
        {
            if(colour[i] == -1)
            {
                colour[i] = 1-colour[node];
                q.push(i);
            }

            else if(colour[i] == colour[node])
                return false;
        }
    }

    return true;
}

bool checkBipartite(int n, vector<int> adjl[])
{
    int colour[n+1];
    memset(colour, -1, sizeof(colour));

    for(int i=1; i<n+1; i++)
    {
        if(colour[i] == -1)
        {
            if(!bipartiteBFS(i, adjl, colour))
            {
                return false;
            }
        }
    }

    return true;
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

    cout<<checkBipartite(n, adjl);
    return 0;
}

// Bipartite Graph : A Graph that can be coloured using two colours such that no two adjusent nodes have same color

/*
               G------B    
              /        \
     B---G---B          G---B---G
              \        /
               G------B
    // even length cycle: Bipatite Graph
    
                   B  
                /     \
           B---G       G---B---G
               |       |
               G-------B
    // odd length cycle: Not Bipatite Graph
*/