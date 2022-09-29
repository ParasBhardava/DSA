#include <bits/stdc++.h>
using namespace std;

class Trie
{
    struct Trienode
    {
        Trienode *child[26];
        bool endsHere;
    };

    Trienode *root;

    Trienode *getNode()
    {
        Trienode *newnode = new Trienode;
        newnode->endsHere = false;

        for (int i = 0; i < 26; i++)
            newnode->child[i] = NULL;

        return newnode;
    }

public:
    Trie()
    {
        root = getNode();
    }

    void insert(string word)
    {
        Trienode *curr = root;
        int index;

        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';

            if (curr->child[index] == NULL)
                curr->child[index] = getNode();

            curr = curr->child[index];
        }

        curr->endsHere = true;
    }

    void dfs(Trienode *root, string &word, vector<string> &res)
    {
        if (res.size() == 3)
            return;

        if (root->endsHere == true)
            res.push_back(word);

        for (int i = 0; i < 26; i++)
        {
            if (root->child[i] != NULL)
            {
                word.push_back('a' + i);
                dfs(root->child[i], word, res);
                word.pop_back();
            }
        }
    }

    vector<string> getPrefix(string prefix)
    {
        vector<string> res;
        Trienode *curr = root;
        int index;

        for (int i = 0; i < prefix.size(); i++)
        {
            index = prefix[i] - 'a';
            if (curr->child[index] == NULL)
                return res;

            curr = curr->child[index];
        }

        dfs(curr, prefix, res);
        return res;
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("mobile");
    t->insert("mouse");
    t->insert("moneypot");
    t->insert("monitor");
    t->insert("mousepad");

    string searchWord = "mouse";
    vector<vector<string>> res;
    string prefix = "";

    for(int i = 0; i<searchWord.size(); i++)
    {
        prefix.push_back(searchWord[i]);
        res.push_back(t->getPrefix(prefix));
    }

    for(auto i : res)
    {
        for(auto j : i)
            cout<<j<<" ";

        cout<<"\n";
    }

    return 0;
}