#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, vector<int> &colour, vector<vector<int>> &graph, int n, int color)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == 1 && colour[k] == color)
            return false;
    }

    return true;
}

bool solve(int node, vector<int> &colour, int n, int m, vector<vector<int>> &graph)
{
    if (node == n)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, colour, graph, n, i))
        {
            colour[node] = i;
            if (solve(node + 1, colour, n, m, graph))
                return true;
            colour[node] = 0;
        }
    }
    return false;
}

int main()
{
    int n = 4; // no of nodes
    int m = 3; // no of colours
    int e = 5; // no of edges

    vector<vector<int>> graph{
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };

    vector<int> colour(n, 0);
    cout << (solve(0, colour, n, m, graph) == true ? "Possible\n" : "Not possible");

    return 0;
}