#include <bits/stdc++.h>
using namespace std;

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
        {

            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            solve(col + 1, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}
// // Brute force Method
// bool isSafe(int row, int col, vector<string>&board, int n)
// {
//     int dupRow = row;
//     int dupCol = col;

//     // check for upper diagonal
//     while (row >= 0 && col >= 0)
//     {
//         if(board[row][col] == 'Q')
//             return false;

//         row--;
//         col--;
//     }

//     // chek for current row
//     row = dupRow;
//     col = dupCol;
//     while (col >= 0)
//     {
//         if(board[row][col] == 'Q')
//             return false;
//         col--;
//     }

//     // check for lower diagonal
//     row = dupRow;
//     col = dupCol;
//     while (row < n && col >= 0)
//     {
//         if(board[row][col] == 'Q')
//             return false;

//         row++;
//         col--;
//     }

//     return true;
// }

// void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n)
// {
//     if(col == n)
//     {
//         ans.push_back(board);
//         return;
//     }

//     for(int row = 0; row < n; row++)
//     {
//         if(isSafe(row, col, board, n))
//         {
//             board[row][col] = 'Q';
//             solve(col+1, board, ans, n);
//             board[row][col] = '.';
//         }
//     }
// }

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');

    for (int i = 0; i < n; i++)
        board[i] = s;

     vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << "\n";
        cout << "\n";
    }

    return 0;
}