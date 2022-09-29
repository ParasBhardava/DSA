#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, int n, vector<vector<int>> &maze, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dj[])
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && maze[nexti][nextj] == 1)
        {
            vis[i][j] = 1;
            solve(nexti, nextj, n, maze, ans, move + dir[ind], vis, di, dj);
            vis[i][j] = 0;
        }
    }

    // downward
    // if(i+1<n && !vis[i+1][j] && a[i+1][j] == 1) {
    //     vis[i][j] = 1;
    //     solve(i+1, j, n, maze, ans, move + 'D', vis);
    //     vis[i][j] = 0;
    // }

    // // left
    // if(j-1>=0 && !vis[i][j-1] && a[i][j-1] == 1) {
    //     vis[i][j] = 1;
    //     solve(i, j-1, n, maze, ans, move + 'L', vis);
    //     vis[i][j] = 0;
    // }

    // // right
    // if(j+1<n && !vis[i][j+1] && a[i][j+1] == 1) {
    //     vis[i][j] = 1;
    //     solve(i, j+1, n, maze, ans, move + 'R', vis);
    //     vis[i][j] = 0;
    // }

    // // upward
    // if(i-1>=0 && !vis[i-1][j] && a[i-1][j] == 1) {
    //     vis[i][j] = 1;
    //     solve(i-1, j, n, maze, ans, move + 'U', vis);
    //     vis[i][j] = 0;
    // }
}

int main()
{
    int n = 4;
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {1, 1, 1, 1}};

    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};

    if (maze[0][0] == 1)
        solve(0, 0, n, maze, ans, "", vis, di, dj);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}