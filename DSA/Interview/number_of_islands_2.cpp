/*
A 2d grid map ofmrows andncolumns is initially filled with water. We may perform anaddLandoperation which turns the water at position (row, col) into a land. Given a list of positions to operate,count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Input:
n = 3, m = 3, positions = [[0,0], [0,1], [1,2], [2,1], [2,2]]

Output:
[1,1,2,3]

0 0 0
0 0 0
0 0 0

1 0 0
0 0 0   Number of islands = 1
0 0 0

1 1 0
0 0 0   Number of islands = 1
0 0 0

1 1 0
0 0 1   Number of islands = 2
0 0 0

1 1 0
0 0 1   Number of islands = 3
0 1 0


1 1 0
0 0 1   Number of islands = 2
0 1 1

*/

#include <bits/stdc++.h>
using namespace std;

class DSU
{

public:
    vector<int> parent, size;

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(-1);
            size.push_back(1);
        }
    }

    int findParent(int node)
    {
        if (parent[node] == node || parent[node] == -1)
            return parent[node];

        return (parent[node] = findParent(parent[node]));
    }

    void Union(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }

        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

vector<int> numIslands(int n, int m, vector<vector<int>> &pos)
{

    DSU dsu(m * n);

    vector<int> dx{-1, 0, 1, 0};
    vector<int> dy{0, 1, 0, -1};
    vector<int> ans;
    int count = 0;

    for (auto &it : pos)
    {
        int x = it[0];
        int y = it[1];

        int lc = x * m + y;

        if (dsu.findParent(lc) != -1)
        {
            ans.push_back(count);
            continue;
        }

        dsu.parent[lc] = lc;
        count++;

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m)
            {
                lc = dsu.findParent(lc);
                int parSide = dsu.findParent(newX * m + newY);
                if (parSide != -1 && parSide != lc)
                {
                    dsu.Union(lc, parSide);
                    count--;
                }
            }
        }

        ans.push_back(count);
    }

    return ans;
}

int main()
{
    int n = 3, m = 3;
    vector<vector<int>> pos = {{0, 0}, {0, 1}, {1, 2}, {2, 1}, {2, 2}};
    vector<int> res = numIslands(n, m, pos);

    for (auto it : res)
        cout << it << " ";

    return 0;
}