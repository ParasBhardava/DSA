#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>> &board, int i, int j, int count, string &word)
{
    if (count == word.size())
        return true;

    if (i == -1 || i == board.size() || j == -1 || j == board[0].size() || board[i][j] != word[count])
        return false;

    char temp = board[i][j];
    board[i][j] = '#';

    bool check = dfs(board, i + 1, j, count + 1, word) ||
                 dfs(board, i - 1, j, count + 1, word) ||
                 dfs(board, i, j + 1, count + 1, word) ||
                 dfs(board, i, j - 1, count + 1, word);

    board[i][j] = temp;

    return check;
}

int main()
{
    vector<vector<char>> board{ {'A', 'B', 'C', 'E' }, 
                                {'S', 'F', 'C', 'S'}, 
                                { 'A', 'D', 'E', 'E' }
                              };
    string word = "ABCB";   // ABCB

    int n = board.size(), m = board[0].size();
    bool flag = false;
    vector<pair<int, int>> first;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0])
                first.push_back({i, j});
        }
    }

    for (int i = 0; i < first.size(); i++)
    {
        if (dfs(board, first[i].first, first[i].second, 0, word))
            flag = true;
    }

    
    if(flag)
        cout << "word present\n";

    else
        cout << "word not present\n";

    return 0;
}