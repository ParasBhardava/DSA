#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void DFS(int start, vector<vector<int>>&adj, vector<bool>&visited)
{
    visited[start] = true;
    cout<<start<<" ";
    
    for(auto it = adj[start].begin(); it != adj[start].end(); it++)
    {
        if(!visited[*it])
        {
            DFS(*it, adj, visited);
        }
    }
}

int main()
{
    int n, m , start;
    cin >> n >> m;
    
    vector<bool>visited(n+1, false);
    vector<vector<int>>adj(n+1);
    
    for(int i = 0; i<m; i++)
    {
        int x, y;
        cin >> x >> y;
        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> start;
    
    // BFS
    queue<int>q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        
        for(auto it = adj[node].begin(); it != adj[node].end(); it++ )
        {
            if(!visited[*it])
            {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
    cout<<"\n";
    
    for(int i = 0; i<n+1; i++)
        visited[i] = false;
    
    // DFS
    DFS(start, adj, visited);
    
    return 0;
}