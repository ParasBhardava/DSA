#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int par, int size, vector<vector<int>> &adjl, vector<vector<int>> &parent)
{
    parent[node][0] = par;
    for (int i = 1; i <= size; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (int it : adjl[node])
    {
        if (it != par)
            dfs(it, node, size, adjl, parent);
    }
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
    dfs(1, 1, size, adjl, parent);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= size; j++)
            cout << parent[i][j] << " ";
        cout << "\n";
    }

    return 0;
}