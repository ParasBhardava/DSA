#include <bits/stdc++.h>
using namespace std;

class Trie
{
    struct Trienode
    {
        char val;
        int endsHere;
        string word;
        Trienode *child[26];
    };

    Trienode *getNode(char c)
    {
        Trienode *newnode = new Trienode;
        ;
        newnode->val = c;
        newnode->endsHere = 0;
        newnode->word = "";

        for (int i = 0; i < 26; i++)
            newnode->child[i] = NULL;

        return newnode;
    }

public:
    Trienode *root = getNode('/');

    void insert(string s)
    {
        Trienode *curr = root;
        int index, i = 0;

        for (int i = 0; i < s.size(); i++)
        {
            index = s[i] - 'a';
            if (curr->child[index] == NULL)
                curr->child[index] = getNode(s[i]);

            curr = curr->child[index];
        }

        curr->endsHere = true;
        curr->word = s;
    }

    void solve(vector<vector<char>> &board, int i, int j, int r, int c, vector<string> &ans, Trienode *curr)
    {
        int index = board[i][j] - 'a';

        if (board[i][j] == '$' || curr->child[index] == NULL)
            return;

        curr = curr->child[index];
        if (curr->endsHere > 0)
        {
            ans.push_back(curr->word);
            curr->endsHere -= 1;
        }

        char ch = board[i][j];
        board[i][j] = '$';

        if (i > 0)
            solve(board, i - 1, j, r, c, ans, curr);

        if (i < r - 1)
            solve(board, i + 1, j, r, c, ans, curr);

        if (j > 0)
            solve(board, i, j - 1, r, c, ans, curr);

        if (j < c - 1)
            solve(board, i, j + 1, r, c, ans, curr);

        board[i][j] = ch;
    }
};

int main()
{

    vector<vector<char>> board{{'o', 'a', 'a', 'n'},
                               {'e', 't', 'a', 'e'},
                               {'i', 'h', 'k', 'r'},
                               {'i', 'f', 'l', 'v'}};

    vector<string> words{"oath", "pea", "eat", "rain"};

    int r = board.size();
    int c = board[0].size();

    Trie *t = new Trie();

    for (int i = 0; i < words.size(); i++)
        t->insert(words[i]);

    vector<string> ans;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            t->solve(board, i, j, r, c, ans, t->root);
        }
    }
    
    for(string s : ans)
        cout << s <<" ";

    return 0;
}