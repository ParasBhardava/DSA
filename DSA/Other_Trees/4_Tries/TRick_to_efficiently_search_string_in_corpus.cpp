#include <bits/stdc++.h>
using namespace std;

class Trie
{
    struct Trienode
    {
        char val;
        int endsHere;
        Trienode *child[26];
    };

    Trienode *root;

    Trienode *getNode(char ch)
    {
        Trienode *newnode = new Trienode;
        newnode->val = ch;
        newnode->endsHere = 0;

        for (int i = 0; i < 26; i++)
            newnode->child[i] = NULL;

        return newnode;
    }

public:
    Trie()
    {
        root = getNode('/');
    }

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

        curr->endsHere += 1;
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

        return (curr->endsHere > 0);
    }
};

int main()
{
    vector<string> dictionary{"any", "tech", "techie", "anime"};
    vector<string> search{"tech", "tem", "techi"};

    Trie *t = new Trie();
    for(int i = 0; i<dictionary.size(); i++)
        t->insert(dictionary[i]);

    cout<<"Words present in dictionary are : "; 
    for(int i = 0; i<search.size(); i++)
    {
        if(t->search(search[i]))
            cout<<search[i]<<" ";
    } 

    return 0;
}