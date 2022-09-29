#include <bits/stdc++.h>
using namespace std;

class Trie
{
    struct Trienode
    {
        bool endsHere;
        Trienode *child[26];
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
};


int main()
{
    Trie *t = new Trie();
    
    // Write your code here
}