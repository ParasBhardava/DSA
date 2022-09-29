#include <bits/stdc++.h>
using namespace std;

void shortestPath(int n, vector<pair<int, int>> adjl[], int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n + 1, INT_MAX);

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for (auto i : adjl[prev])
        {
            int next = i.first;
            int nextDist = i.second;

            if (nextDist + dist < distance[next])
            {
                distance[next] = nextDist + dist;
                pq.push({distance[next], next});
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
        cout << distance[i] << " ";

    cout << "\n";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adjl[n + 1];

    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;

        adjl[x].push_back({y, wt});
        adjl[y].push_back({x, wt});
    }
    int start = 1;

    shortestPath(n, adjl, start);

    return 0;
}