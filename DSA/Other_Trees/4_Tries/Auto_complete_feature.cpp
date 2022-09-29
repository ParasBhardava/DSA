#include <bits/stdc++.h>
using namespace std;

class Trie
{
    struct Trienode
    {
        char val;
        int endshere;
        Trienode *child[26];
    };

    Trienode *getNode(char ch)
    {
        Trienode *newnode = new Trienode();
        newnode->val = ch;
        newnode->endshere = 0;

        for (int i = 0; i < 26; i++)
            newnode->child[i] = NULL;

        return newnode;
    }

public:
    Trienode *root = getNode('/');

    void insert(string word)
    {
        Trienode *curr = root;
        int index;

        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
                curr->child[index] = getNode(word[i]);

            curr = curr->child[index];
        }

        curr->endshere += 1;
    }

    void printAllSuggestions(string word)
    {
        Trienode *curr = root;
        int index;
        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
            {
                cout << "No string found with this prefix : " << word << "\n";
            }

            curr = curr->child[index];
        }

        vector<string> res;
        allSuggestions(curr, word, res, "");

        for (auto &s : res)
            cout << word << s << "\n";
    }

    void allSuggestions(Trienode *curr, string &word, vector<string> &res, string temp)
    {
        if (curr == NULL)
            return;

        if (curr->endshere)
            res.push_back(temp);

        for (int i = 0; i < 26; i++)
        {
            if (curr->child[i] != NULL)
                allSuggestions(curr->child[i], word, res, temp + char(i + 'a'));
        }
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("hel");
    t->insert("hell");
    t->insert("hello");
    t->insert("help");
    t->insert("helps");
    t->insert("helping");
    t->insert("a");
    t->insert("cat");
    t->insert("dog");


    string str;
    cin>>str;
    t->printAllSuggestions(str);

    return 0;
}