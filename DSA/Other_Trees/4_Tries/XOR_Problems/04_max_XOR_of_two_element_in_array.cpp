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

    int getMax(int num)
    {
        Trienode *curr = root;
        int bit;
        int maxXor = 0;
        
        for(int i = 31; i >= 0; i--)
        {
            bit = (num >> i) & 1;
            if(curr->child[1 - bit] != NULL)
            {
               curr = curr->child[1 - bit];
               maxXor |= (1 << i); 
            }

            else if(curr->child[bit] != NULL)
            {
                curr = curr->child[bit];
            }
        }

        return maxXor;
    }
};

int main()
{
    vector<int> arr{3,10,5,25,2,8};
    // vector<int> arr{9, 5, 3};

    Trie *t = new Trie();

    int maxXor = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        maxXor = max(maxXor, t->getMax(arr[i]));
        t->insert(arr[i]);
    }

    cout<<maxXor<<"\n";

    return 0;
}