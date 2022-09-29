#include<bits/stdc++.h>
using namespace std;

class Trie
{
    struct Trienode
    {
        char val;
        int count;
        int endsHere;
        Trienode *child[26];
    };

    Trienode *root;

    Trienode *getNode(int index)
    {
        Trienode *newnode = new Trienode;
        newnode->val = 'a' + index;
        newnode->count = 0;
        newnode->endsHere = 0;
        
        for(int i = 0; i<26; i++)
            newnode->child[i] = NULL;

        return newnode;
    }

    public : 
    Trie()
    {
        root = getNode('/' - 'a');
    }

    void insert(string word)
    {
        Trienode *curr = root;
        int index;

        for(int i = 0; i<word.size(); i++)
        {
            index = word[i] - 'a';
            if(curr->child[index] == NULL)
                curr->child[index] = getNode(index);

            curr->child[index]->count += 1;
            curr = curr->child[index];    
        }

        curr->endsHere += 1;
    }

    bool search(string word)
    {
        Trienode *curr = root;
        int index; 

        for(int i = 0; i<word.size(); i++)
        {
            index = word[i] - 'a';
            if(curr->child[index] == NULL)
                return false;

            curr = curr->child[index];    
        }

        return (curr->endsHere > 0);  
    }

    bool startsWith(string prefix)
    {
        Trienode *curr = root;
        int index; 

        for(int i = 0; i<prefix.size(); i++)
        {
            index = prefix[i] - 'a';
            if(curr->child[index] == NULL)
                return false;

            curr = curr->child[index];    
        }

        return (curr->count > 0);  
    }

};

int main()
{
    Trie *t = new Trie();
    t->insert("apple");

    cout<<t->search("apple")<<"\n";
    cout<<t->search("app")<<"\n";
    cout<<t->startsWith("app")<<"\n";

    return 0;
}