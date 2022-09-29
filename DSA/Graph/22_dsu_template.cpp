#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, size;

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;

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

// class DSU
// {
// public:
//     unordered_map<int, int> parent;

// public:
//     int findParent(int node)
//     {
//         if (parent[node] == node)
//             return node;

//         return parent[node] = findParent(parent[node]);
//     }

//     void Union(int u, int v)
//     {
//         if (parent.count(u) == 0)
//             parent[u] = u;

//         if (parent.count(v) == 0)
//             parent[v] = v;

//         int pu = findParent(u);
//         int pv = findParent(v);

//         if (pu != pv)
//             parent[pu] = pv;
//     }

//     int componants()
//     {
//         int count = 0;
//         for (auto &it : parent)
//         {
//             int u = it.first;
//             if (parent[u] == u)
//                 count++;
//         }

//         return count;
//     }
// };

int main()
{
    DSU dsu;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        dsu.Union(x, y + 1000);
    }

    cout << dsu.componants() - 1 << "\n";

    return 0;
}