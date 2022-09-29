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

    bool Delete(string word)
    {
        if(search(word))
        {
            Trienode *curr = root;
            int index;

            for(int i = 0; i<word.size(); i++)
            {
                index = word[i]-'a';
                curr = curr->child[index];
            }

            curr->endsHere -= 1;

            return true;
        }

        else
        {
            cout<<"word is not present !\n";
            return false;
        }
    }

};

int main()
{

    Trie *t = new Trie();

    t->insert("ab");
    t->insert("aba");
    t->insert("bab");
    t->insert("b");
    t->insert("abc");
    t->insert("ab");

    t->Delete("ba");

    cout<<t->search("bab")<<"\n";
    t->Delete("bab");
    cout<<t->search("bab")<<"\n";

    cout<<t->search("abc")<<"\n";
    t->Delete("abc");
    cout<<t->search("abc")<<"\n";

    t->Delete("ab");
    cout<<t->search("ab")<<"\n";

    return 0;
}