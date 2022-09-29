#include<bits/stdc++.h>
using namespace std;

class Trie
{
    struct Trienode
    {
        Trienode *child[2];
    };

    Trienode *root;

    Trienode *getNode()
    {
        Trienode *newnode = new Trienode;
        newnode->child[0] = NULL;
        newnode->child[1] = NULL;

        return newnode;
    }

    public:
    Trie()
    {
        root = getNode();
    }


    void insert(int num)
    {
        Trienode *curr = root;
        int bit;
        for(int i = 31; i >=0; i--)
        {
            bit = (num >> i) & 1;
            if(curr->child[bit] == NULL)
                curr->child[bit] = getNode();

            curr = curr->child[bit];
        }
    }

    int getMax(int num)
    {
        int maxNum = 0;
        Trienode *curr = root;
        int bit;
        
        for(int i = 31; i >= 0; i--)
        {
            bit = (num >> i) & 1;
            
            if(curr->child[1-bit] != NULL)
            {
                maxNum |= (1 << i);
                curr = curr->child[1-bit];
            }

            else
            {
                curr = curr->child[bit]; 
            }
        }

        return maxNum;
    }
};

int main()
{
    Trie *t = new Trie();
    int n = 5;
    vector<int>arr{9, 8, 7, 5, 4};  // 1 0 15 13 12

    for(auto &i : arr)
        t->insert(i);

    int k = 8;
    cout<<t->getMax(k)<<" ";

    return 0;
}