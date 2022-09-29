// Problem Link: https://codeforces.com/problemset/problem/1337/C

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int par, int l, vector<int> &level, vector<int> &subtree, vector<vector<int>> &adjl)
{
    int sum = 0;
    level[node] = l;
    for (int it : adjl[node])
    {
        if (it != par)
        {
            dfs(it, node, l + 1, level, subtree, adjl);
            sum += subtree[it];
        }
    }

    sum++;
    subtree[node] = sum;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adjl(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }

    vector<int> level(n + 1, 0);
    vector<int> subtree(n + 1, 0);

    dfs(1, 0, 1, level, subtree, adjl);
    vector<int> contribution;
    for (int i = 1; i <= n; i++)
        contribution.push_back(level[i] - subtree[i]);

    sort(contribution.begin(), contribution.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < k; i++)
        ans += contribution[i];

    cout << ans << " ";

    return 0;
}