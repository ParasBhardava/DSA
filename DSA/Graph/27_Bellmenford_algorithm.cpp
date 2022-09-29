// not work for negative cycle
// used in detect negative cycle

// steps :
// Relax all the edges N-1 times
// if(dist[u] + weight < dist[v])
//     dis[v] = dis[u]+weight

// again check for one more time : if any distance change then there is a negative cycle

#include <bits/stdc++.h>
using namespace std;

class node
{

    public :

    int u, v, weight;
    node(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->weight = wt;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    int src;
    cin >> src;

    int inf = 10000000;
    vector<int> dist(n, inf);

    dist[src] = 0;

    for(int i = 0; i<=n-1; i++)
    {
        for(auto it : edges)
        {
            if(dist[it.u] + it.weight < dist[it.v])
                dist[it.v] = dist[it.u] + it.weight;
        }
    }

    bool flag = false;
    for(auto it: edges)
    {
        if(dist[it.u] + it.weight < dist[it.v])
        {
            cout<<"Negative Cycle !\n";
            flag = true;
            break;
        }
    }

    if(!flag)
    {
        for(int i = 0; i<n; i++)
            cout<<i<<" "<<dist[i]<<"\n";
    }

    return 0;
}

// Time complexitiy : O(N-1) * O(E)
// Space complexity : O(N)