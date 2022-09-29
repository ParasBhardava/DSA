#include <bits/stdc++.h>
using namespace std;

class Trie
{
    struct Trienode
    {
        bool endsHere;
        Trienode *child[26];
        int count;
    };

    Trienode *root;

    Trienode *getNode()
    {
        Trienode *newnode = new Trienode;
        newnode->endsHere = false;
        newnode->count = 0;

        for (int i = 0; i < 26; i++)
            newnode->child[i] = NULL;

        return newnode;
    }

public:
    Trie()
    {
        root = getNode();
    }

    void insert(string word, int val)
    {
        Trienode *curr = root;
        int index;

        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
                curr->child[index] = getNode();

            curr->child[index]->count += val;
            curr = curr->child[index];
        }

        curr->endsHere = true;
    }

    bool search(string word)
    {
        Trienode *curr = root;
        int index;

        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
                return false;

            curr = curr->child[index];
        }

        return curr->endsHere;
    }

    void update(string word, int val)
    {
        Trienode *curr = root;
        int index;

        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            // if (curr->child[index] != NULL)
                curr->child[index]->count = val;
        }
    }

    int prefixCount(string word)
    {
        Trienode *curr = root;
        int index;

        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
                return 0;

            curr = curr->child[index];
        }

        return curr->count;
    }
};


int main()
{
    Trie *t = new Trie();
    t->insert("apple", 3);

    cout<<t->search("apple")<<" ";
    t->update("apple", 2);

    cout<<t->prefixCount("app");
}