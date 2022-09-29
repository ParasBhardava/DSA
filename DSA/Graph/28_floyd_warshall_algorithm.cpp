// Used in negative edge weight
// more useful in dence graph
// if digonal element of distane array is negative(dist[i][i] < 0) then graph contain negative cycle
// This algo not work with negative cycle.(detect negative cycle)
// No need to check for rest of element

#include <bits/stdc++.h>
using namespace std;
#define INF 100000000

int main()
{
    vector<vector<int>> graph = {{0, 5, INF, 10},
                                 {INF, 0, 3, INF},
                                 {INF, INF, 0, 1},
                                 {INF, INF, INF, 0}};

    int n = graph.size();
    vector<vector<int>> dist = graph;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";

            else
                cout << dist[i][j] << " ";
        }

        cout << "\n";
    }

    // shortest path between node 1 and 3 is dist[1][3]
    return 0;
}
