// Used in Kruskal's algorithm

#include <bits/stdc++.h>
using namespace std;

int Parent[100001], Rank[100001];

void makeSet()
{
    for (int i = 1; i <= 100000; i++)
    {
        Parent[i] = i;
        Rank[i] = 0;
    }
}

int findParent(int node)
{
    if (node == Parent[node])
        return node;

    return (Parent[node] = findParent(Parent[node]));
}

// Union by Rank
void Union(int u, int v)
{
    u = findParent(u);
    v = findParent(v);

    if (u == v)
        return;

    if (Rank[u] < Rank[v])
        Parent[u] = v;

    else if (Rank[v] < Rank[u])
        Parent[v] = u;

    else
    {
        Parent[v] = u;
        Rank[u]++;
    }
}

// Union by Size
// void Union(int u, int v)
// {
//     u = findParent(u);
//     v = findParent(v);

//       if(u == v)
//            return;
//
//     if(size[u] < size[v])
//     {
//         Parent[u] = v;
//         size[v] +=  size[u];
//     }

//     else
//     {
//         Parent[v] =  u;
//         size[u] += size[v];
//     }
// }

int main()
{
    makeSet();
    int m;
    cin >> m;

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    // if 2 and 3 belong o the same companent or not
    if (findParent(2) != findParent(3))
        cout << "Different Component\n";

    else
        cout << "Same Component\n";

    return 0;
}