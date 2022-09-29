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
    Trie() { root = getNode(); }

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
                maxXor |= (1 << i);
                curr = curr->child[1-bit];
            }
            else
            {
                curr = curr->child[bit];
            }
        }

        return maxXor;
    }


};

int main()
{
    Trie *t = new Trie();

    vector<int> arr{8, 1, 2, 12, 7, 6};
    int preXor = arr[0];
    int maxXor = arr[0];
    t->insert(arr[0]);

    for(int i = 1; i < arr.size(); i++)
    {
        preXor = preXor ^ arr[i];

        // Take full don't remove
        maxXor = max(maxXor, preXor);

        // find how much we can remove
        maxXor = max(maxXor, t->getMax(preXor));

        t->insert(preXor);
    }

    cout<<maxXor<<"\n";
    return 0;
}