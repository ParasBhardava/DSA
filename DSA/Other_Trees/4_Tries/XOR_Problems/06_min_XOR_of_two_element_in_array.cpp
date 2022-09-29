#include <bits/stdc++.h>
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
        Trienode *newnode = new Trienode();
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

        for (int i = 31; i >= 0; i--)
        {
            bit = (num >> i) & 1;

            if (curr->child[bit] == NULL)
                curr->child[bit] = getNode();

            curr = curr->child[bit];
        }
   }

    int getMin(int num)
    {
        Trienode *curr = root;
        int bit;
        int minXor = 0;
        
        for(int i = 31; i >= 0; i--)
        {
            bit = (num >> i) & 1;
            if(curr->child[bit] != NULL)
            {
               curr = curr->child[bit];
            }

            else if(curr->child[1-bit] != NULL)
            {
                curr = curr->child[1-bit];
                minXor |= (1 << i);
            }
        }

        return minXor;
    }
};

int main()
{
    // vector<int> arr{1, 2, 3, 4, 5};
    vector<int> arr{9, 5, 3};

    Trie *t = new Trie();
    t->insert(arr[0]);

    int minXor = arr[0] ^ arr[1];
    for (int i = 1; i < arr.size(); i++)
    {
        minXor = min(minXor, t->getMin(arr[i]));
        t->insert(arr[i]);
    }

    cout<<minXor<<"\n";

    return 0;
}