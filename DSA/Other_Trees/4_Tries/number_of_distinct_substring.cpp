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
        newnode->endsHere = true;

        for(int i = 0; i < 26; i++)
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
        int index, count = 0;

        for(int i = 0; i<word.size(); i++)
        {
            index = word[i] - 'a';
            if(curr->child[index] == NULL)
            {
                count++;
                curr->child[index] = getNode();
            }

            curr = curr->child[index];
        }

        return count;
    }
};

int main()
{
    string str = "aaaa";
    Trie *t = new Trie();
    int count = 0;

    for(int i = 0; i<str.size(); i++)
    {
        string temp = "";
        for(int j = i; j<str.size(); j++)
        {
            temp.push_back(str[j]);
            count += t->insert(temp);
        }
    }

    cout<<count<<"\n";

    return 0;
}

// paras ---> 14

// p
// pa
// par
// para
// paras

// a
// ar
// ara
// aras

// r
// ra
// ras

// a      ---> repeated
// as

// s