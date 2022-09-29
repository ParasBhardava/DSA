#include<bits/stdc++.h>
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

    Trienode * getNewnode(char ch)
    {
        Trienode *newnode = new Trienode;
        newnode->val = ch;
        newnode->endsHere = 0;

        for(int i = 0; i<26; i++)
            newnode->child[i] = NULL;

        return newnode;
    }

    public:
    Trie()
    {
        root = getNewnode('/');
    }

    void insert(string word)
    {
        Trienode *curr = root;
        int index;

        for(int i = 0; i<word.size(); i++)
        {
            index = word[i]-'a';
            if(curr->child[index] == NULL)
                curr->child[index] = getNewnode(word[i]);

            curr = curr->child[index];
        }

        curr->endsHere += 1;
    }

    bool trieSearch(string word, Trienode *curr, int pos, int n)
    {
        if(word[pos] == '.')
        {
            bool res = false;
            Trienode *current = curr;
            
            for(int i = 0; i<26; i++)
            {
                if(pos == n-1 && curr->child[i])
                {
                    current = curr->child[i];
                    res  = res || (current->endsHere > 0 ? true : false);
                }

                else if(curr->child[i] && trieSearch(word, curr->child[i], pos+1, n))
                {
                    return true;
                }
            }
            return res;
        }

        else if(curr->child[word[pos]-'a'])
        {
            if(pos == n-1)
            {
                curr = curr->child[word[pos] - 'a'];
                return (curr->endsHere > 0 ? true : false);
            }

            return trieSearch(word, curr->child[word[pos]-'a'], pos+1, n);
        }

        return false;
    }

    bool search(string word)
    {
        return trieSearch(word, root, 0, word.size());
    }

};


int main()
{
    vector<string>dictionaray{"ad", "add", "be", "ben", "beq", "bet"};
    vector<string>search{"ad", "add", "ben", "b.", "b.t", "b..", "...", "..q", ".", ".be", "ab."};

    Trie *t = new Trie();
    for(int i = 0; i<dictionaray.size(); i++)
        t->insert(dictionaray[i]);

    cout<<"Words are present in dictionary :\n";
    for(int i = 0; i<search.size(); i++)
    {
        if(t->search(search[i]))
            cout<<search[i]<<"\n";
    }        

    return 0;
}

// Time complexity : O(n + 26^N)
//                 Insert + search