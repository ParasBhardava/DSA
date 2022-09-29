#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int par, int l, int size, vector<vector<int>> &adjl, vector<vector<int>> &parent, vector<int> &level)
{
    level[node] = l;

    parent[node][0] = par;
    for (int i = 1; i <= size; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int it : adjl[node])
    {
        if (it != par)
            dfs(it, node, l + 1, size, adjl, parent, level);
    }
}

int lca(int u, int v, int size, vector<vector<int>> &parent, vector<int> &level)
{
    if (level[v] > level[u])
        swap(u, v);

    int k = level[u] - level[v];

    // brings u and v to the same level
    int count = 0;
    while (k)
    {
        if (k & 1)
            u = parent[u][count];

        count++;
        k >>= 1;
    }

    if (u == v)
        return u;

    // keep jumping till not equal
    for (int i = size; i >= 0; i--)
    {
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    // top guy above the both u and v is lca
    return parent[u][0];
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adjl(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }

    int size = ceil(log2(n));
    vector<vector<int>> parent(n + 1, vector<int>(size + 1, -1));
    vector<int> level(n + 1);
    dfs(1, 1, 1, size, adjl, parent, level);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= size; j++)
            cout << parent[i][j] << " ";
        cout << "\n";
    }

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v, size, parent, level) << "\n";
    }

    return 0;
}