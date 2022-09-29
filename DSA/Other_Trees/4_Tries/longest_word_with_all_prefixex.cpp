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
        Trienode *newnode = new Trienode();
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

    int insert(string word)
    {
        Trienode *curr = root;
        int index;

        int count = 0;

        for (int i = 0; i < word.size(); i++)
        {
            index = word[i] - 'a';
            if (curr->child[index] == NULL)
                curr->child[index] = getNode();

            if(curr->child[index]->endsHere == true)
                count++;

            curr = curr->child[index];
        }

        curr->endsHere = true;
        return count;
    }

};

int main()
{
    vector<string> words{"a", "banana", "app", "appl", "ap", "apply", "apple"};

    sort(words.begin(), words.end());
    Trie *t = new Trie();
    string res = "";

    for(int i = 0; i<words.size(); i++)
    {
        int count = t->insert(words[i]);
        if(count == words[i].size()-1 && words[i].size() > res.size())
            res = words[i];
    }

    cout<<res<<"\n";

    return 0;
}