#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adjl[n];

    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        adjl[x].push_back({y, wt});
        adjl[y].push_back({x, wt});
    }

    int parent[n];
    int key[n];
    bool mstSet[n];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    parent[0] = -1;
    key[0] = 0;
    minHeap.push({0, 0});

    while (!minHeap.empty())
    {
        int u = minHeap.top().second;
        minHeap.pop();
        mstSet[u] = true;

        for (auto i : adjl[u])
        {
            int v = i.first;
            int weight = i.second;
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
                minHeap.push({key[v], v});
            }
        }
    }

    int cost = accumulate(key, key + n, 0);
    cout << cost << "\n";
    for (int i = 1; i < n; i++)
        cout << i << " - " << parent[i] << "\n";

    return 0;
}