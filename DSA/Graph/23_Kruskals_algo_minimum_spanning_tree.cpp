#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u;
    int v;
    int weight;

    node(int u, int v, int weight)
    {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
};

bool compare(node a, node b)
{
    return a.weight < b.weight;
}

int findParent(int node, vector<int> &parent)
{
    if (node == parent[node])
        return node;

    return parent[node] = findParent(parent[node], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v])
        parent[u] = v;

    else if (rank[v] < rank[u])
        parent[v] = u;

    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

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

    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cost = 0;
    vector<pair<int, int>> mst;

    for (auto i : edges)
    {
        if (findParent(i.v, parent) != findParent(i.u, parent))
        {
            cost += i.weight;
            mst.push_back({i.u, i.v});
            Union(i.u, i.v, parent, rank);
        }
    }

    cout << cost << "\n";
    for (auto i : mst)
        cout << i.first << " - " << i.second << "\n";

    return 0;
}